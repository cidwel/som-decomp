.setcpu "65816"
.segment "CODE"
.org $9E6C
map_control_0d9e6c:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
