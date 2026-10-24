.setcpu "65816"
.segment "CODE"
.org $2318
map_control_0c2318:
    .byte $F1 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
