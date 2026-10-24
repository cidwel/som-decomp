.setcpu "65816"
.segment "CODE"
.org $86AF
map_control_0c86af:
    .byte $EE ; backreference distance high bits
    .byte $96 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
