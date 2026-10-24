.setcpu "65816"
.segment "CODE"
.org $9E18
map_control_0d9e18:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
