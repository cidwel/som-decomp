.setcpu "65816"
.segment "CODE"
.org $91DE
map_control_0d91de:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
