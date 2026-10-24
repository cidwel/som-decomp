.setcpu "65816"
.segment "CODE"
.org $44DA
map_control_0c44da:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
