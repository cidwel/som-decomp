.setcpu "65816"
.segment "CODE"
.org $74E2
map_control_0f74e2:
    .byte $EE ; backreference distance high bits
    .byte $16 ; distance low bit/count
