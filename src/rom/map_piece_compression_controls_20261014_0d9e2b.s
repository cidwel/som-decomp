.setcpu "65816"
.segment "CODE"
.org $9E2B
map_control_0d9e2b:
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
