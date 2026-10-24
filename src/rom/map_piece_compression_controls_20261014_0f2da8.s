.setcpu "65816"
.segment "CODE"
.org $2DA8
map_control_0f2da8:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
