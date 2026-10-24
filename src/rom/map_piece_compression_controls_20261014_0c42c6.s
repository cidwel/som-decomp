.setcpu "65816"
.segment "CODE"
.org $42C6
map_control_0c42c6:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
