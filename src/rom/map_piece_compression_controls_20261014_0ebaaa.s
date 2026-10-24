.setcpu "65816"
.segment "CODE"
.org $BAAA
map_control_0ebaaa:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
