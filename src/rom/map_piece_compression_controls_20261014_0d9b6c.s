.setcpu "65816"
.segment "CODE"
.org $9B6C
map_control_0d9b6c:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
