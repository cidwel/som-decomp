.setcpu "65816"
.segment "CODE"
.org $AEAA
map_control_0eaeaa:
    .byte $EC ; backreference distance high bits
    .byte $06 ; distance low bit/count
