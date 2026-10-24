.setcpu "65816"
.segment "CODE"
.org $769C
map_control_0f769c:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
