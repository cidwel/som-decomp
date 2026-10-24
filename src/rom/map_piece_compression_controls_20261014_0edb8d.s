.setcpu "65816"
.segment "CODE"
.org $DB8D
map_control_0edb8d:
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
