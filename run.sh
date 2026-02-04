#!/bin/bash
set -e

ROOT_DIR="$(cd "$(dirname "$0")" && pwd)"
DIST_DIR="$ROOT_DIR/dist"

# === Functions ===

create_new_file() {
  YEAR=$(date +%y)
  MONTH=$(date +%m)
  DAY=$(date +%d)

  DIR_NAME="learn_${YEAR}_${MONTH}_${DAY}"
  DIR_PATH="$ROOT_DIR/$DIR_NAME"

  echo "📁 Using directory: $DIR_PATH"
  mkdir -p "$DIR_PATH"

  read -p "📝 Enter new C++ file name (without .cpp, you can include subfolders like 'folder/file'): " FILE_NAME

  # Add .cpp automatically
  [[ "$FILE_NAME" != *.cpp ]] && FILE_NAME="${FILE_NAME}.cpp"

  FILE_PATH="$DIR_PATH/$FILE_NAME"

  # Make sure parent directories exist
  mkdir -p "$(dirname "$FILE_PATH")"

  if [ -f "$FILE_PATH" ]; then
    echo "⚠️ File already exists: $FILE_PATH"
  else
    cat > "$FILE_PATH" <<EOF
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, world!" << endl;
    return 0;
}
EOF
    echo "✅ Created: $FILE_PATH"
  fi

  read -p "Do you want to compile and run it now? (y/n): " RUN_NOW
  if [[ "$RUN_NOW" == "y" || "$RUN_NOW" == "Y" ]]; then
    run_cpp_file "$FILE_PATH"
  fi
}

run_cpp_file() {
  while true; do
    SRC_FILE="$1"

    if [ -z "$SRC_FILE" ]; then
      read -p "📂 Filename: " SRC_FILE
    fi

    # If no folder path, prepend today's folder
    if [[ "$SRC_FILE" != */* ]]; then
      YEAR=$(date +%y)
      MONTH=$(date +%m)
      DAY=$(date +%d)
      TODAY_DIR="$ROOT_DIR/learn_${YEAR}_${MONTH}_${DAY}"
      SRC_FILE="$TODAY_DIR/$SRC_FILE"
    fi

    # Add .cpp automatically if missing
    [[ "$SRC_FILE" != *.cpp ]] && SRC_FILE="${SRC_FILE}.cpp"

    if [ ! -f "$SRC_FILE" ]; then
      echo "❌ Error: File not found → $SRC_FILE"
      SRC_FILE=""  # Reset to prompt again
      continue
    fi

    mkdir -p "$DIST_DIR"

    # Make unique binary name
    REL_PATH="${SRC_FILE#$ROOT_DIR/}"
    BIN_NAME="${REL_PATH//\//_}"
    BIN_NAME="${BIN_NAME%.cpp}"

    echo "🔧 Compiling: $SRC_FILE"
    g++ "$SRC_FILE" -o "$DIST_DIR/$BIN_NAME" -std=c++17 -Wall
    echo "✅ Build complete → $DIST_DIR/$BIN_NAME"

    # clear the terminal for good output
    # clear
    echo "🚀 Running: $DIST_DIR/$BIN_NAME"
    "$DIST_DIR/$BIN_NAME"
    break
  done
}

clear_dist_folder() {
  if [ -d "$DIST_DIR" ]; then
    read -p "⚠️ Are you sure you want to delete all files in dist/? (y/n): " CONFIRM
    if [[ "$CONFIRM" == "y" || "$CONFIRM" == "Y" ]]; then
      rm -rf "$DIST_DIR"/*
      echo "✅ dist/ folder cleared."
    else
      echo "❌ Operation canceled."
    fi
  else
    echo "ℹ️ dist/ folder does not exist."
  fi
}

# === Main Menu ===
echo "==============================="
echo "  ⚙️  C++ Runner & Creator"
echo "==============================="
echo "1) Create new file"
echo "2) Run existing file"
echo "3) Clear dist/ folder"
echo "==============================="

read -p "Choose an option [1-3]: " OPTION

case $OPTION in
  1)
    create_new_file
    ;;
  2)
    run_cpp_file
    ;;
  3)
    clear_dist_folder
    ;;
  *)
    echo "❌ Invalid option."
    exit 1
    ;;
esac
