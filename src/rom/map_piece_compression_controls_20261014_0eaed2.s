.setcpu "65816"
.segment "CODE"
.org $AED2
map_control_0eaed2:
    .byte $EC ; backreference distance high bits
    .byte $06 ; distance low bit/count
