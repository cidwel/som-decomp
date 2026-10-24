.setcpu "65816"
.segment "CODE"
.org $12AD
map_control_0c12ad:
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
