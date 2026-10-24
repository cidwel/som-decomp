.setcpu "65816"
.segment "CODE"
.org $DC36
map_control_0ddc36:
    .byte $E8 ; backreference distance high bits
    .byte $46 ; distance low bit/count
