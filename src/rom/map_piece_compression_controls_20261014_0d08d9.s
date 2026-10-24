.setcpu "65816"
.segment "CODE"
.org $08D9
map_control_0d08d9:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E4 ; previous-row copy count
