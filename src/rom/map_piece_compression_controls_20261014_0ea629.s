.setcpu "65816"
.segment "CODE"
.org $A629
map_control_0ea629:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
