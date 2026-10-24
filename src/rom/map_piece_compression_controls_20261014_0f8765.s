.setcpu "65816"
.segment "CODE"
.org $8765
map_control_0f8765:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
