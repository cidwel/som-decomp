.setcpu "65816"
.segment "CODE"
.org $54EB
map_control_0c54eb:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
