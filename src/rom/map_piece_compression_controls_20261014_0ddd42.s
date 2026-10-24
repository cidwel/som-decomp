.setcpu "65816"
.segment "CODE"
.org $DD42
map_control_0ddd42:
    .byte $EE ; backreference distance high bits
    .byte $87 ; distance low bit/count
