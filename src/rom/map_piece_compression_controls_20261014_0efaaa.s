.setcpu "65816"
.segment "CODE"
.org $FAAA
map_control_0efaaa:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
