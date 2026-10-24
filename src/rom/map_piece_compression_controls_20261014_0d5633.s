.setcpu "65816"
.segment "CODE"
.org $5633
map_control_0d5633:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
