// Modules to control application life and create native browser window
const {app, BrowserWindow, Menu, Tray, nativeImage} = require('electron')
const path = require('path')

function createWindow () {
  // Create the browser window.
  const mainWindow = new BrowserWindow({
    width: 800,
    height: 600,
    minWidth: 800,
    minHeight: 600,
    // maxWidth: 800,
    // maxHeight: 600,
    icon:'./favicon.ico',
    webPreferences: {  // 首选项设置
      backgroundThrottling: false,   //设置应用在后台正常运行
      nodeIntegration:true,     //设置能在页面使用nodejs的API
      contextIsolation: false,  //关闭警告信息
      preload: path.join(__dirname, './src/preload.js')
    }
  })

  // 系统托盘
  let icon = nativeImage.createFromPath(path.join(__dirname, './favicon.ico'));
  let tray = new Tray(icon);
  tray.setToolTip('惠花生商家收款工具');
  tray.setTitle('惠花生商家收款工具1');
  tray.on('right-click', () => {
    const template = [
      {
        label:'显示主界面',
        click:()=>{
          mainWindow.show();
        }
      },
      {
        label:'退出',
        click:()=>{
          app.quit();
        }
      }
    ]
    tray.popUpContextMenu(Menu.buildFromTemplate(template));
  })

  // 菜单栏
  const template = [
    {
      label: '文件',
      submenu: [
        {
          label: '切换账号',
          click: function () {
            alert('切换账号')
          }
        },
        {
          label: '退出登录',
          click: function () {
            alert('退出登录')
          }
        },
      ]
    }
  ];
  Menu.setApplicationMenu(Menu.buildFromTemplate(template))

  // 加载页面文件
  mainWindow.loadFile('src/index.html')

  // 开启调试工具
  // mainWindow.webContents.openDevTools()
}

// This method will be called when Electron has finished
// initialization and is ready to create browser windows.
// Some APIs can only be used after this event occurs.
app.whenReady().then(() => {
  createWindow()

  app.on('activate', function () {
    // On macOS it's common to re-create a window in the app when the
    // dock icon is clicked and there are no other windows open.
    if (BrowserWindow.getAllWindows().length === 0) createWindow()
  })
})

// Quit when all windows are closed, except on macOS. There, it's common
// for applications and their menu bar to stay active until the user quits
// explicitly with Cmd + Q.
app.on('window-all-closed', function () {
  if (process.platform !== 'darwin') app.quit()
})

// In this file you can include the rest of your app's specific main process
// code. You can also put them in separate files and require them here.
