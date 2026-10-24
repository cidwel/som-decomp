.setcpu "65816"
.segment "CODE"
.org $3575
map_control_0e3575:
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
