# OpenLamborghino Project

## Overview
OpenLamborghino is a project designed to work with the PlatformIO ecosystem. This document provides setup instructions for using the project in **CLion** with the **PlatformIO plugin** and the **PlatformIO CLI**.

---

## Prerequisites

Before setting up the project, ensure you have the following installed:

1. **CLion IDE**
    - Download and install CLion from [JetBrains](https://www.jetbrains.com/clion/).

2. **PlatformIO Plugin for CLion**
    - In CLion, navigate to `File > Settings > Plugins`.
    - Search for "PlatformIO" and install the plugin.

3. **PlatformIO Core (CLI)**
    - Install PlatformIO CLI by following the instructions at [PlatformIO Installation](https://platformio.org/install/cli).
    - Verify installation:
      ```bash
      pio --version
      ```

4. **CMake** (optional, CLion will use its bundled version by default).

---

## Setting Up the Project in CLion

### Step 1: Clone or Extract the Project

1. If you have a zip file, extract it to a preferred directory.
    - Example path: `/path/to/OpenLamborghino-main`.

2. If using Git:
   ```bash
   git clone https://github.com/MikaGaete/OpenLamborghino.git
   cd OpenLamborghino
   ```

### Step 2: Open Project in CLion

1. Launch CLion.
2. Click on `Open` and select the extracted/cloned project directory.
    - Example: `/path/to/OpenLamborghino-main`
3. CLion will automatically detect the `CMakeLists.txt` or prompt to configure CMake (if applicable).

### Step 3: Configure PlatformIO in CLion

1. Open the `platformio.ini` file located in the root of the project.
2. Ensure your `platformio.ini` file contains the correct configuration for your hardware.
    - Example:
      ```ini
      [env:your_environment]
      platform = espressif32
      board = esp32dev
      framework = arduino
      ```

3. Sync the project with PlatformIO:
    - Navigate to `Tools > PlatformIO` and select `Rebuild CMake Project`.

### Step 4: Build and Upload the Project

1. Open the PlatformIO panel in CLion.
2. Use the following options:
    - **Build**: To compile the project.
    - **Upload**: To upload the compiled binary to your device.