.setcpu "65816"
.segment "CODE"
.org $700A
map_control_0e700a:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
