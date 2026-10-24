.setcpu "65816"
.segment "CODE"
.org $EAD0
map_control_0fead0:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
