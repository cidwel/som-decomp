.setcpu "65816"
.segment "CODE"
.org $6F2B
map_control_0f6f2b:
    .byte $EE ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $87 ; distance low bit/count
