.setcpu "65816"
.segment "CODE"
.org $BFB2
map_control_0fbfb2:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
