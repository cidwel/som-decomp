.setcpu "65816"
.segment "CODE"
.org $4592
map_control_0f4592:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
