.setcpu "65816"
.segment "CODE"
.org $6EF3
map_control_0f6ef3:
    .byte $EE ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $87 ; distance low bit/count
