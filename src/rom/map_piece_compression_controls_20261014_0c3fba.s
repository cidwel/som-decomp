.setcpu "65816"
.segment "CODE"
.org $3FBA
map_control_0c3fba:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
