.setcpu "65816"
.segment "CODE"
.org $19C9
map_control_0e19c9:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $08 ; distance low bit/count
