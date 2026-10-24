.setcpu "65816"
.segment "CODE"
.org $466E
map_control_0f466e:
    .byte $EC ; backreference distance high bits
    .byte $88 ; distance low bit/count
