.setcpu "65816"
.segment "CODE"
.org $E566
map_control_0fe566:
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
