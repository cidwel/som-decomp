.setcpu "65816"
.segment "CODE"
.org $91D2
map_control_0f91d2:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
