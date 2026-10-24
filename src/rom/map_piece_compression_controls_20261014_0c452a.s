.setcpu "65816"
.segment "CODE"
.org $452A
map_control_0c452a:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
