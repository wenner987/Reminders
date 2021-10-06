set -u -e -x

function clean() {
  rm -rf ./build
  exit
}

if [ $1 = "clean" ]; then
  clean
fi

# 记住当前位置
old_dir=$(pwd)

# 创建编译目录
if [ ! -d "build" ]; then
  mkdir build
fi

# 编译
cd build
cmake ../
make -j$2
cp -r ${old_dir}/res ./

# 执行
./rem

cd ${old_dir}
