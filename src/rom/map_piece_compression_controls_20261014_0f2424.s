.setcpu "65816"
.segment "CODE"
.org $2424
map_control_0f2424:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
