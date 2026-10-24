.setcpu "65816"
.segment "CODE"
.org $124A
map_control_0f124a:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
