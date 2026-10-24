.setcpu "65816"
.segment "CODE"
.org $6654
map_control_0d6654:
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
