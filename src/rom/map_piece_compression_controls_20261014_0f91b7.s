.setcpu "65816"
.segment "CODE"
.org $91B7
map_control_0f91b7:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
