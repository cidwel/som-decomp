.setcpu "65816"
.segment "CODE"
.org $D2C7
map_control_0ed2c7:
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
