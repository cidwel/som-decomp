.setcpu "65816"
.segment "CODE"
.org $2B3C
map_control_0c2b3c:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count
