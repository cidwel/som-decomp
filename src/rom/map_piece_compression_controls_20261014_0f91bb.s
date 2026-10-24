.setcpu "65816"
.segment "CODE"
.org $91BB
map_control_0f91bb:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
