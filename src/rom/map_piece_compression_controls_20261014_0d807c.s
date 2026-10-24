.setcpu "65816"
.segment "CODE"
.org $807C
map_control_0d807c:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
