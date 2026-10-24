.setcpu "65816"
.segment "CODE"
.org $6D5B
map_control_0d6d5b:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
