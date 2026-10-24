.setcpu "65816"
.segment "CODE"
.org $351F
map_control_0f351f:
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
