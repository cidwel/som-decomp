.setcpu "65816"
.segment "CODE"
.org $9241
map_control_0c9241:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
