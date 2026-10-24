.setcpu "65816"
.segment "CODE"
.org $2FBA
map_control_0f2fba:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
