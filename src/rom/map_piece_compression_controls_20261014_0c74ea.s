.setcpu "65816"
.segment "CODE"
.org $74EA
map_control_0c74ea:
    .byte $EE ; backreference distance high bits
    .byte $09 ; distance low bit/count
