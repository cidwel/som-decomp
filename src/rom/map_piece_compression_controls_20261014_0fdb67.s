.setcpu "65816"
.segment "CODE"
.org $DB67
map_control_0fdb67:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
