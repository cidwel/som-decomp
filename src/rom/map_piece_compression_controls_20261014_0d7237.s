.setcpu "65816"
.segment "CODE"
.org $7237
map_control_0d7237:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
