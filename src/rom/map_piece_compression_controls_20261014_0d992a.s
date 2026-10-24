.setcpu "65816"
.segment "CODE"
.org $992A
map_control_0d992a:
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
