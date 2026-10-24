.setcpu "65816"
.segment "CODE"
.org $2DB0
map_control_0e2db0:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
