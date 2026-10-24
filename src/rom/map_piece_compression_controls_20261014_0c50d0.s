.setcpu "65816"
.segment "CODE"
.org $50D0
map_control_0c50d0:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $8A ; distance low bit/count
