.setcpu "65816"
.segment "CODE"
.org $DB8C
map_control_0ddb8c:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
