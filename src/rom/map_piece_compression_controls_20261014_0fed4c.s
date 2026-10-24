.setcpu "65816"
.segment "CODE"
.org $ED4C
map_control_0fed4c:
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
