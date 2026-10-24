.setcpu "65816"
.segment "CODE"
.org $85AD
map_control_0d85ad:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
