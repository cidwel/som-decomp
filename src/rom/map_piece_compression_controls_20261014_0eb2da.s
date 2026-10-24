.setcpu "65816"
.segment "CODE"
.org $B2DA
map_control_0eb2da:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
