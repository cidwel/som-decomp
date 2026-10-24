.setcpu "65816"
.segment "CODE"
.org $1AD0
map_control_0c1ad0:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
