.setcpu "65816"
.segment "CODE"
.org $2EFF
map_control_0f2eff:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
