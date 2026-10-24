.setcpu "65816"
.segment "CODE"
.org $1323
map_control_0c1323:
    .byte $E2 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $89 ; distance low bit/count
