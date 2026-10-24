.setcpu "65816"
.segment "CODE"
.org $C171
map_control_0ec171:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
