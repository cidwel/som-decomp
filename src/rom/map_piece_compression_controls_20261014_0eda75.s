.setcpu "65816"
.segment "CODE"
.org $DA75
map_control_0eda75:
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E1 ; previous-row copy count
