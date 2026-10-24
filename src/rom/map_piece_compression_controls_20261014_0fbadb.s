.setcpu "65816"
.segment "CODE"
.org $BADB
map_control_0fbadb:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
