.setcpu "65816"
.segment "CODE"
.org $50B6
map_control_0c50b6:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $8A ; distance low bit/count
