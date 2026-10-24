.setcpu "65816"
.segment "CODE"
.org $5FC2
map_control_0c5fc2:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
