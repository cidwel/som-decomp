.setcpu "65816"
.segment "CODE"
.org $6EC0
map_control_0f6ec0:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
