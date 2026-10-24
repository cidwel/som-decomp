.setcpu "65816"
.segment "CODE"
.org $D4FC
map_control_0ed4fc:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
