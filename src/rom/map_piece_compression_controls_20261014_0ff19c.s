.setcpu "65816"
.segment "CODE"
.org $F19C
map_control_0ff19c:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
