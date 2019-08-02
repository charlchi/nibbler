
if ! [ -x "$(command -v brew)" ]; then
  echo 'Homebrew not installed. Installing now.' >&2
  sh -c "$(curl -fsSL https://raw.githubusercontent.com/wethinkcode/homebrew/master/install.sh)"
  echo 'Open a new terminal and run this script again.' >&2
  exit 1
else
  echo 'Homebrew already installed.' >&2
fi

if brew ls --versions cmake > /dev/null; then
  echo 'Cmake already installed.' >&2
  # The package is installed
else
  echo 'Cmake not installed. Installing now.' >&2
  brew install cmake
fi

cd lib2
curl -L https://github.com/glfw/glfw/releases/download/3.3/glfw-3.3.bin.MACOS.zip > glfw.zip
unzip glfw.zip
mkdir include
mkdir include/GLFW
cp glfw-*/include/GLFW/glfw3.h include/GLFW/glfw3.h
cp glfw-*/lib-macos/libglfw3.a libglfw3.a
# rm glfw.zip
# rm -rf glfw-*
# rm glfw.zip

echo 'Installation done.' >&2