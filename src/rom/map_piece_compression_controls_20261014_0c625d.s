.setcpu "65816"
.segment "CODE"
.org $625D
map_control_0c625d:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
