.setcpu "65816"
.segment "CODE"
.org $FC89
map_control_0efc89:
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
