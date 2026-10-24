.setcpu "65816"
.segment "CODE"
.org $EFFE
map_control_0eeffe:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
