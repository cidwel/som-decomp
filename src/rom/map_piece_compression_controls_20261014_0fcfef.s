.setcpu "65816"
.segment "CODE"
.org $CFEF
map_control_0fcfef:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
