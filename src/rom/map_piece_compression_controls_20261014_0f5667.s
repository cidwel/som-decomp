.setcpu "65816"
.segment "CODE"
.org $5667
map_control_0f5667:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
