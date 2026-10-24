.setcpu "65816"
.segment "CODE"
.org $BE85
map_control_0fbe85:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
