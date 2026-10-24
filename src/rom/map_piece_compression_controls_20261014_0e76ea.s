.setcpu "65816"
.segment "CODE"
.org $76EA
map_control_0e76ea:
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
