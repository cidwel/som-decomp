.setcpu "65816"
.segment "CODE"
.org $9173
map_control_0c9173:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
