.setcpu "65816"
.segment "CODE"
.org $7749
map_control_0e7749:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
