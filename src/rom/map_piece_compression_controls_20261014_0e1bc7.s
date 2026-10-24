.setcpu "65816"
.segment "CODE"
.org $1BC7
map_control_0e1bc7:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
