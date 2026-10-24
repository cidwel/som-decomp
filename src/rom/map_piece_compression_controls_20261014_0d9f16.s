.setcpu "65816"
.segment "CODE"
.org $9F16
map_control_0d9f16:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
