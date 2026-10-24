.setcpu "65816"
.segment "CODE"
.org $EAD0
map_control_0dead0:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
