let device, characteristic;

// Bluetooth接続を行う関数
document.getElementById('connect').addEventListener('click', async () => {
  try {
    // ユーザーにデバイスの選択を求める
    device = await navigator.bluetooth.requestDevice({
      acceptAllDevices: true,
      optionalServices: ['YOUR_SERVICE_UUID'] // ここにESP32のサービスUUIDを入れる
    });

    // 選択されたデバイスに接続
    const server = await device.gatt.connect();
    const service = await server.getPrimaryService('YOUR_SERVICE_UUID'); // ここにESP32のサービスUUIDを入れる
    characteristic = await service.getCharacteristic('YOUR_CHARACTERISTIC_UUID'); // ここにESP32のキャラクタリスティックUUIDを入れる

    console.log('Bluetoothデバイスに接続しました！');
  } catch (error) {
    console.log('Bluetooth接続に失敗しました: ' + error);
  }
});

// コマンドをESP32に送信する関数
function sendCommand(command) {
  if (device && characteristic) {
    characteristic.writeValue(new TextEncoder().encode(command));
  }
}

// 各方向ボタンにイベントリスナーを設定
['on', 'off'].forEach(direction => {
  document.getElementById(direction).addEventListener('click', () => {
    sendCommand(direction);
    console.log('コマンド送信: ' + direction);
  });
});


   
