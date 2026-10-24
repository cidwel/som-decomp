.setcpu "65816"
.segment "CODE"
.org $6CE3
map_control_0d6ce3:
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
