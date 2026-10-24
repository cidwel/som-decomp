.setcpu "65816"
.segment "CODE"
.org $FA85
map_control_0efa85:
    .byte $F1 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
