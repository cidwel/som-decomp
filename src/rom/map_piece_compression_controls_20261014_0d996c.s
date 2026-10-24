.setcpu "65816"
.segment "CODE"
.org $996C
map_control_0d996c:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
