.setcpu "65816"
.segment "CODE"
.org $599D
map_control_0c599d:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
