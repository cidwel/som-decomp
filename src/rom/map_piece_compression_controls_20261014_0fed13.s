.setcpu "65816"
.segment "CODE"
.org $ED13
map_control_0fed13:
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
