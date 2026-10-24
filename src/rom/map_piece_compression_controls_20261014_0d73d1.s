.setcpu "65816"
.segment "CODE"
.org $73D1
map_control_0d73d1:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
