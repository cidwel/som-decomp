.setcpu "65816"
.segment "CODE"
.org $65ED
map_control_0d65ed:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
