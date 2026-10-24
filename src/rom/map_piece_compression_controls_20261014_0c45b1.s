.setcpu "65816"
.segment "CODE"
.org $45B1
map_control_0c45b1:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
