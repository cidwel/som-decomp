.setcpu "65816"
.segment "CODE"
.org $8836
map_control_0c8836:
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
