.setcpu "65816"
.segment "CODE"
.org $5ECD
map_control_0c5ecd:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
