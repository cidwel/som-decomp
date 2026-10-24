.setcpu "65816"
.segment "CODE"
.org $5079
map_control_0e5079:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
