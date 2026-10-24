.setcpu "65816"
.segment "CODE"
.org $F83B
map_control_0cf83b:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
