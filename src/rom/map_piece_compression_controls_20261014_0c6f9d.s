.setcpu "65816"
.segment "CODE"
.org $6F9D
map_control_0c6f9d:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
