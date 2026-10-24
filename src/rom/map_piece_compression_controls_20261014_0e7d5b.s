.setcpu "65816"
.segment "CODE"
.org $7D5B
map_control_0e7d5b:
    .byte $E8 ; backreference distance high bits
    .byte $3E ; distance low bit/count
