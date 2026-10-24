.setcpu "65816"
.segment "CODE"
.org $BEDD
map_control_0fbedd:
    .byte $ED ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
