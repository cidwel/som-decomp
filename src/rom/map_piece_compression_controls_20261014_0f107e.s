.setcpu "65816"
.segment "CODE"
.org $107E
map_control_0f107e:
    .byte $EE ; backreference distance high bits
    .byte $8E ; distance low bit/count
