.setcpu "65816"
.segment "CODE"
.org $99DA
map_control_0d99da:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
