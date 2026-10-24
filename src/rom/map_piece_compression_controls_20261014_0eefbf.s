.setcpu "65816"
.segment "CODE"
.org $EFBF
map_control_0eefbf:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
