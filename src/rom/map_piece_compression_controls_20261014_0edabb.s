.setcpu "65816"
.segment "CODE"
.org $DABB
map_control_0edabb:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
