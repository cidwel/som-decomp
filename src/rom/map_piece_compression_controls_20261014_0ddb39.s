.setcpu "65816"
.segment "CODE"
.org $DB39
map_control_0ddb39:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
