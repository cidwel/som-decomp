.setcpu "65816"
.segment "CODE"
.org $25BC
map_control_0e25bc:
    .byte $F4 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
