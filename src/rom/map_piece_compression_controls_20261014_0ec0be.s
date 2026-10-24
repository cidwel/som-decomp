.setcpu "65816"
.segment "CODE"
.org $C0BE
map_control_0ec0be:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
