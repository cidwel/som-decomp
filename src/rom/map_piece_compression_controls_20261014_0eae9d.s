.setcpu "65816"
.segment "CODE"
.org $AE9D
map_control_0eae9d:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
