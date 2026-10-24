.setcpu "65816"
.segment "CODE"
.org $32F2
map_control_0e32f2:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
