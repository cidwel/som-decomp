.setcpu "65816"
.segment "CODE"
.org $19BA
map_control_0e19ba:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $07 ; distance low bit/count
