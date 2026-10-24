.setcpu "65816"
.segment "CODE"
.org $91CD
map_control_0c91cd:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
