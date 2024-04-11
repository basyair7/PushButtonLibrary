# Push Button Library
- Library ini berfungsi untuk menjalankan program push button
- Library ini terdiri dari beberapa fungsi diantaranya
## Fungsi Library
- countPushButton(long delayPush, long delayReset); -> menghitung nilai selama ditekan dan akan kembali ke nilai 0 jika dilepas
- countPushNoReset(long delayPush); -> menghitung nilai selama ditekan dan tidak akan kembali ke nilai 0 jika di lepaskan
- digitalReadPushButton(); -> return hasil 0 atau 1
- analogReadPushButton(); -> return hasil sesuai dengan pembacaan pin Analog (0 - 1023)
- resetCount(); -> reset kembali nilai dari fungsi countPushButton / countPushNoReset