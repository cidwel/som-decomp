.setcpu "65816"
.segment "CODE"
.org $C023
map_control_0dc023:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $29 ; distance low bit/count
