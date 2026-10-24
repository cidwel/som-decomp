.setcpu "65816"
.segment "CODE"
.org $DB7A
map_control_0edb7a:
    .byte $E9 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
