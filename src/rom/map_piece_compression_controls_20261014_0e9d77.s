.setcpu "65816"
.segment "CODE"
.org $9D77
map_control_0e9d77:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
