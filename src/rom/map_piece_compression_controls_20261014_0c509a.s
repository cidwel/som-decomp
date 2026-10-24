.setcpu "65816"
.segment "CODE"
.org $509A
map_control_0c509a:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $8A ; distance low bit/count
