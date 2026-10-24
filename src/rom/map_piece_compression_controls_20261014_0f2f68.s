.setcpu "65816"
.segment "CODE"
.org $2F68
map_control_0f2f68:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
