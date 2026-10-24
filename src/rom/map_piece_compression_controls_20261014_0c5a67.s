.setcpu "65816"
.segment "CODE"
.org $5A67
map_control_0c5a67:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
