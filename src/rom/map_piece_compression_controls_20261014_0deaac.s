.setcpu "65816"
.segment "CODE"
.org $EAAC
map_control_0deaac:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
