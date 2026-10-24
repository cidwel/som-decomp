.setcpu "65816"
.segment "CODE"
.org $F570
map_control_0df570:
    .byte $F2 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
