#!/bin/bash

# Reset
Reset='\033[0m'           # Text Reset

# Regular Colors
Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White

ring_bell() {
  # Use the shell's audible bell.
  if [[ -t 1 ]]
  then
    printf "\a"
  fi
}

# Determine OS
OS="$OSTYPE"

# Determine Architecture
ARCH=$(uname -m)

# Check for bash
if [ -v "${BASH_VERSION:-}" ]
then
    echo $Red">>"$Reset" Bash is required to interpret this script."
else
    echo $Yellow">>"$Reset" Found bash"
    which bash
fi


# OS Specific Operations
echo $Yellow">>"$Reset" Detecting Operating System"
case "$OS" in
  solaris*)
    echo "Solaris" ;;
  darwin*)
    echo "OSX";;
  linux*)
    echo "Linux";;
  bsd*)
    echo "FreeBSD" ;;
  msys*)
    echo "Windows Bash/msysGit" ;;
  cygwin*)
    echo "Windows Cygwin" ;;
  *)
    echo -e "${RED}ERROR:${WHITE}"
    echo "Unknown OS: $OSTYPE"
    echo "Software is not compatible with architecture"
    exit 1 ;;
esac

if [[ "$ARCH" == x86_64* ]]; then
    echo "X64"
elif [[ "$ARCH" == i*86 ]]; then
    echo "X32"
elif  [[ "$ARCH" == arm* ]]; then
    echo "ARM"
fi

# Check for Homebrew
echo "Detecting Homebrew"
if [[ $(command -v brew) == "" ]]; then
    echo $Yellow">>"$Reset" Installing Homebrew"
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
else
    echo $Yellow">>"$Reset" Found brew"
    which brew
fi

# Check for ruby
echo $Yellow">>"$Reset" Detecting ruby"
if [[ $(command -v ruby) == "" ]]; then
    echo $Yellow">>"$Reset" Installing ruby"
    brew install ruby
else
    echo $Yellow">>"$Reset" Found ruby"
    which ruby
fi
echo $Yellow">>"$Reset" Detecting ruby - done"

# Check for cmake
echo $Yellow">>"$Reset" Detecting cmake"
if [[ $(command -v cmake) == "" ]]; then
    echo $Yellow">>"$Reset" Installing cmake"
    brew install cmake
else
    echo $Yellow">>"$Reset" Found cmake"
    which cmake
fi
echo $Yellow">>"$Reset" Detecting cmake - done"

# Check for git
echo $Yellow">>"$Reset" Detecting git"
if [[ $(command -v git) == "" ]]; then
    echo $Yellow"In"$Reset"stalling git"
    brew install git
else
    echo $Yellow">>"$Reset" Found git:"
    which git
fi
echo $Yellow">>"$Reset" Detecting git - done"
