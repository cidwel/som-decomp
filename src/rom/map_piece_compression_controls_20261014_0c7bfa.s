.setcpu "65816"
.segment "CODE"
.org $7BFA
map_control_0c7bfa:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
