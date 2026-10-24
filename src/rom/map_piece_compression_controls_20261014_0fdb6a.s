.setcpu "65816"
.segment "CODE"
.org $DB6A
map_control_0fdb6a:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
