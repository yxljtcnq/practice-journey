@echo off
chcp 65001 >nul
echo ======================================
echo          一键提交代码到Gitee
echo ======================================
echo.

echo [1/3] 正在添加所有修改的文件...
git add .

echo.
echo [2/3] 正在提交代码...
set /p "msg=请输入提交备注（直接回车默认：update code）："
if "%msg%"=="" set "msg=update code"
git commit -m "%msg%"

echo.
echo [3/3] 正在推送到远程仓库...
git push origin master

echo.
echo ✅ 代码提交完成！
pause
