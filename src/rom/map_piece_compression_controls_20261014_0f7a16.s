.setcpu "65816"
.segment "CODE"
.org $7A16
map_control_0f7a16:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
