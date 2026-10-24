.setcpu "65816"
.segment "CODE"
.org $5D0C
map_control_0c5d0c:
    .byte $EE ; backreference distance high bits
    .byte $8A ; distance low bit/count
