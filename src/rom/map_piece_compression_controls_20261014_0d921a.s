.setcpu "65816"
.segment "CODE"
.org $921A
map_control_0d921a:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
