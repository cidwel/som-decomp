.setcpu "65816"
.segment "CODE"
.org $15BF
map_control_0f15bf:
    .byte $E7 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
