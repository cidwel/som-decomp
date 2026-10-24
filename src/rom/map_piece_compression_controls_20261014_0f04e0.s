.setcpu "65816"
.segment "CODE"
.org $04E0
map_control_0f04e0:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
