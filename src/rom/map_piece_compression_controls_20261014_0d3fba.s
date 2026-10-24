.setcpu "65816"
.segment "CODE"
.org $3FBA
map_control_0d3fba:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
