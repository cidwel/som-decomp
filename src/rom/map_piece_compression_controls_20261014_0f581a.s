.setcpu "65816"
.segment "CODE"
.org $581A
map_control_0f581a:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
