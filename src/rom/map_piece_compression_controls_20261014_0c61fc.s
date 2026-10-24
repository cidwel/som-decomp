.setcpu "65816"
.segment "CODE"
.org $61FC
map_control_0c61fc:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
