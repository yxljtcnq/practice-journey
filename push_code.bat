@echo off
chcp 65001 >nul
echo ==============================================
echo          全自动Git提交推送脚本 (全能版)
echo ==============================================
echo.

:: 1. 拉取远程最新代码 (避免冲突)
git pull origin master
echo.

:: 2. 添加所有【源码+工程文件】(自动忽略.gitignore里的垃圾文件)
git add .
echo ✅ 已添加所有代码和工程文件

:: 3. 自动提交 (支持自定义备注，默认写"更新代码")
set /p msg=请输入提交备注(直接回车默认: 更新代码):
if not defined msg set msg=更新代码
git commit -m "%msg%"
echo ✅ 已完成提交

:: 4. 推送到远程仓库
git push origin master
echo.
echo ✅ 推送成功！所有代码已同步到Gitee
echo.

pause