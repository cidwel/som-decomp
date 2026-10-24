.setcpu "65816"
.segment "CODE"
.org $F31B
map_control_0cf31b:
    .byte $F5 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $18 ; distance low bit/count
