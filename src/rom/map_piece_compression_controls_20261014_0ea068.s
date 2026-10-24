.setcpu "65816"
.segment "CODE"
.org $A068
map_control_0ea068:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
