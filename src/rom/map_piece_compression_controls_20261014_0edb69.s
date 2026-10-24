.setcpu "65816"
.segment "CODE"
.org $DB69
map_control_0edb69:
    .byte $E9 ; backreference distance high bits
    .byte $87 ; distance low bit/count
