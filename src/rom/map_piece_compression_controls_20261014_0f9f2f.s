.setcpu "65816"
.segment "CODE"
.org $9F2F
map_control_0f9f2f:
    .byte $EE ; backreference distance high bits
    .byte $09 ; distance low bit/count
