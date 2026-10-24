.setcpu "65816"
.segment "CODE"
.org $DDFC
map_control_0dddfc:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
