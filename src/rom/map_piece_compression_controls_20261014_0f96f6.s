.setcpu "65816"
.segment "CODE"
.org $96F6
map_control_0f96f6:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
