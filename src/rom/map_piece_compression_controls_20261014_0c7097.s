.setcpu "65816"
.segment "CODE"
.org $7097
map_control_0c7097:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
