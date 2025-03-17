#* CS100-Ray-Tracing for course recitation.
#* 
#* Copyright (C) 2023 - 2025
#* Author: Haizhao Dai
#* Email: daihzh2023@shanghaitech.edu.cn
#* 
#* This program is free software: you can redistribute it and/or modify
#* it under the terms of the GNU General Public License as published by
#* the Free Software Foundation, either version 3 of the License, or
#* (at your option) any later version.
#* 
#* This program is distributed in the hope that it will be useful,
#* but WITHOUT ANY WARRANTY; without even the implied warranty of
#* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#* GNU General Public License for more details.
#* 
#* You should have received a copy of the GNU General Public License
#* along with this program.  If not, see <http://www.gnu.org/licenses/>.

import os
from pathlib import Path
import subprocess as sp
import sys

from PIL import Image


def info(message) -> None:
    print(f"\033[34m{message}\033[0m")

def error(message) -> None:
    print(f"\033[31m{message}\033[0m", file=sys.stderr)

def run(**kwargs) -> None:
    if sys.platform == "win32":
        result = sp.run(**kwargs, encoding="utf-8")
    else:
        result = sp.run(**kwargs, shell=True, encoding="utf-8")

    if result.returncode != 0:
        error(f"Error in executing: {kwargs['args']}, got {result.returncode}")
        sys.exit(1)

cwd = Path.cwd()
if cwd.name == "script":
    cwd = cwd.parent
    os.chdir(cwd)

build_dir = cwd.joinpath("build")
if not build_dir.exists():
    build_dir.mkdir(exist_ok=True)

output_dir = cwd.joinpath("output")
if not output_dir.exists():
    output_dir.mkdir(exist_ok=True)


info("[script] Compiling...")
run(args="gcc src/*.c -o build/CS100-Ray-Tracing -I include -O3 -std=c17 -Wall -Wextra -Wpedantic -Werror -lm")

ppm_file = output_dir.joinpath("image.ppm")
png_file = ppm_file.with_suffix(".png")

info("[script] Generating ppm file...")
with open(ppm_file, "w") as f:
    run(args="./build/CS100-Ray-Tracing", stdout=f)

info("[script] Converting ppm file to png file...")
Image.open(ppm_file).save(png_file)
info(f"[script] Everything done. Check your image in {str(png_file)}")
