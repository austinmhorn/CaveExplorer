# c++ compiler
CXX := g++
# compiler flags
CXX_VERSION_FLAG := -std=c++17

# paths
SRCDIR := src
HDRDIR := $(SRCDIR)
BUILDDIR := build
BINDIR := bin
TARGET := CaveExplorer

SRCEXT := cpp
HDREXT := hpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
LIBS := sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network
INC := -I include
CXXFLAGS := -L /usr/local/lib -l $(LIBS) -Wl,-rpath /Library/Frameworks

$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	@echo "\033[38;5;8m==> \033[0m\033[32;1mLinking\033[0m..."
	$(CXX) $(CXX_VERSION_FLAG) $^ -o $(BINDIR)/$(TARGET) $(INC) $(CXXFLAGS)
	@echo "\033[38;5;8m==> Created Unix Executable :\033[38;5;10m" $(TARGET) "\033[0m\033[38;5;8min" "\""$(BINDIR)"\"" "folder\033[0m"

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT) $(HDRDIR)/%.$(HDREXT)
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(BUILDDIR)/Core
	@mkdir -p $(BUILDDIR)/State
	@mkdir -p $(BUILDDIR)/State/Base
	@mkdir -p $(BUILDDIR)/Entity
	@mkdir -p $(BUILDDIR)/Entity/Base
	@mkdir -p $(BUILDDIR)/UI
	@mkdir -p $(BUILDDIR)/UI/GUI
	@mkdir -p $(BUILDDIR)/UI/GUI/Elements
	@mkdir -p $(BUILDDIR)/UI/GUI/Elements/Button
	@mkdir -p $(BUILDDIR)/UI/GUI/Elements/Button/Base
	@mkdir -p $(BUILDDIR)/UI/GUI/Shapes
	@echo "\033[38;5;8m==>\033[0m \033[34;1mCompiling\033[0m..."
	$(CXX) $(CXX_VERSION_FLAG) -Wall $(INC) -c -o $@ $<

clean:
	@echo "\033[38;5;8m==>\033[0m \033[33;1mCleaning\033[0m..."
	$(RM) -r $(BUILDDIR)
	$(RM) -r $(BINDIR)

run:
	@./$(BINDIR)/$(TARGET)
	
.PHONY: clean
