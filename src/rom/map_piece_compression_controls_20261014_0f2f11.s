.setcpu "65816"
.segment "CODE"
.org $2F11
map_control_0f2f11:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
