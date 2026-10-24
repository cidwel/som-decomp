.setcpu "65816"
.segment "CODE"
.org $3F0A
map_control_0d3f0a:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
