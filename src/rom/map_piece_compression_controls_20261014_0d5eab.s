.setcpu "65816"
.segment "CODE"
.org $5EAB
map_control_0d5eab:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
