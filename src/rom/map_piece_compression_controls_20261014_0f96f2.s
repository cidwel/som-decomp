.setcpu "65816"
.segment "CODE"
.org $96F2
map_control_0f96f2:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
