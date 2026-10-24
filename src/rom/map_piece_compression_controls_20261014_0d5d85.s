.setcpu "65816"
.segment "CODE"
.org $5D85
map_control_0d5d85:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
