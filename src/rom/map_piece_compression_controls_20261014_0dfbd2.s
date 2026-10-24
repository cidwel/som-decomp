.setcpu "65816"
.segment "CODE"
.org $FBD2
map_control_0dfbd2:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
