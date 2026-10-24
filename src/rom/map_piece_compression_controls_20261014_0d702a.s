.setcpu "65816"
.segment "CODE"
.org $702A
map_control_0d702a:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
