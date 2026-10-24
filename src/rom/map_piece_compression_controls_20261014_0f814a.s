.setcpu "65816"
.segment "CODE"
.org $814A
map_control_0f814a:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
