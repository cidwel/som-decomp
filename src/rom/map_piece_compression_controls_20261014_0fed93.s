.setcpu "65816"
.segment "CODE"
.org $ED93
map_control_0fed93:
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
