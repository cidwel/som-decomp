.setcpu "65816"
.segment "CODE"
.org $50F0
map_control_0c50f0:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $8C ; distance low bit/count
