.setcpu "65816"
.segment "CODE"
.org $ECDA
map_control_0eecda:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
