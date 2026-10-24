.setcpu "65816"
.segment "CODE"
.org $F877
map_control_0df877:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
