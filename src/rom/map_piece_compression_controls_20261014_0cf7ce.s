.setcpu "65816"
.segment "CODE"
.org $F7CE
map_control_0cf7ce:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
