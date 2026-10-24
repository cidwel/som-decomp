.setcpu "65816"
.segment "CODE"
.org $3970
map_control_0e3970:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
