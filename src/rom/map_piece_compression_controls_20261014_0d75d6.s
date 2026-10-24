.setcpu "65816"
.segment "CODE"
.org $75D6
map_control_0d75d6:
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
