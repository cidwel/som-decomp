.setcpu "65816"
.segment "CODE"
.org $97E6
map_control_0f97e6:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
