.setcpu "65816"
.segment "CODE"
.org $2FCD
map_control_0f2fcd:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
