.setcpu "65816"
.segment "CODE"
.org $8822
map_control_0c8822:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
