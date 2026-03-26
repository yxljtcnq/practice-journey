@echo off
echo 自动同步：改名 / 新增 / 修改
cd /d "%~dp0"

:: 自动识别改名、新增、改代码
git add .

:: 提交
git commit -m "update: add/rename/edit code" 2>nul

:: 推送
git push

echo ✅ 完成，.gitignore 自动挡住所有垃圾
pause
