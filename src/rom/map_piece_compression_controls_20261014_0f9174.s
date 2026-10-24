.setcpu "65816"
.segment "CODE"
.org $9174
map_control_0f9174:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
