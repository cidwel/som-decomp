.setcpu "65816"
.segment "CODE"
.org $E384
map_control_0de384:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
