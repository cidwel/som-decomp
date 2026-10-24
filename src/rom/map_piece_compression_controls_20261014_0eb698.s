.setcpu "65816"
.segment "CODE"
.org $B698
map_control_0eb698:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
