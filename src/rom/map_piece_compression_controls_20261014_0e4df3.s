.setcpu "65816"
.segment "CODE"
.org $4DF3
map_control_0e4df3:
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
