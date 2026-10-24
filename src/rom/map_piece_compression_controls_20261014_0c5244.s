.setcpu "65816"
.segment "CODE"
.org $5244
map_control_0c5244:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
