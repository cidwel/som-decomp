.setcpu "65816"
.segment "CODE"
.org $4C74
map_control_0d4c74:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
