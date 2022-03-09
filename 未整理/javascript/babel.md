# 一、 简介

> - ES6的某些高级语法无法在浏览器环境中甚至是Node.js环境中运行
> - Babel 可以将ES6的语法转化为ES5的语法，从而避免上述问题
> - 相当于代码转换器

# 二、安装

> Babel 提供babel-cli工具，用于命令行转码，他的安装命令如下：

```bash
npm install -g babel-cli
babel --version
```

## 三、使用

> Babel 的配置文件是.babelrc,存放在项目的根目录下，该文件用来设置转码规则和插件，基本格式如下

```json
{
    "preset": ["es2015"],
    "plugin":
}
```

```bash
# 安装转化器 
npm install --save-dev bable-preset-es2015
# 整个目录
babel src -d dist
# 单个文件
babel xxx.js -o yyy.js
```

> 可以在package.json 里面写脚本使用脚本，相当于c 语言的make

