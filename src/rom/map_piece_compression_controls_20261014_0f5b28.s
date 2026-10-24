.setcpu "65816"
.segment "CODE"
.org $5B28
map_control_0f5b28:
    .byte $EE ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
