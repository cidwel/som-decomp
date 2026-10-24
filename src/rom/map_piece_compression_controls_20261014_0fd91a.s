.setcpu "65816"
.segment "CODE"
.org $D91A
map_control_0fd91a:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
