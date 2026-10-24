.setcpu "65816"
.segment "CODE"
.org $3814
map_control_0d3814:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
