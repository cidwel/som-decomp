.setcpu "65816"
.segment "CODE"
.org $73EE
map_control_0d73ee:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
