.setcpu "65816"
.segment "CODE"
.org $6ED6
map_control_0f6ed6:
    .byte $EE ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $87 ; distance low bit/count
