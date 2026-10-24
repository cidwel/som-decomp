.setcpu "65816"
.segment "CODE"
.org $4929
map_control_0c4929:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
