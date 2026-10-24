.setcpu "65816"
.segment "CODE"
.org $064B
map_control_0f064b:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
