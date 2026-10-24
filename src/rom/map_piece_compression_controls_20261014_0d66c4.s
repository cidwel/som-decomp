.setcpu "65816"
.segment "CODE"
.org $66C4
map_control_0d66c4:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
