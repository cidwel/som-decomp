.setcpu "65816"
.segment "CODE"
.org $FAB9
map_control_0cfab9:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
