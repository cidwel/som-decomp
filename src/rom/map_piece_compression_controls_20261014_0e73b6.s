.setcpu "65816"
.segment "CODE"
.org $73B6
map_control_0e73b6:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
