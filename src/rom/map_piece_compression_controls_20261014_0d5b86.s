.setcpu "65816"
.segment "CODE"
.org $5B86
map_control_0d5b86:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
