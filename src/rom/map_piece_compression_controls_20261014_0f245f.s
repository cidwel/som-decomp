.setcpu "65816"
.segment "CODE"
.org $245F
map_control_0f245f:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
