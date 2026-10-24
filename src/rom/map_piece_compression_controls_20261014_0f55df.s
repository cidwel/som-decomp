.setcpu "65816"
.segment "CODE"
.org $55DF
map_control_0f55df:
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
