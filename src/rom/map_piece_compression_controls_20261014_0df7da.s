.setcpu "65816"
.segment "CODE"
.org $F7DA
map_control_0df7da:
    .byte $F2 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
