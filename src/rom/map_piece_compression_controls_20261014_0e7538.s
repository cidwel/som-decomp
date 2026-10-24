.setcpu "65816"
.segment "CODE"
.org $7538
map_control_0e7538:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
