.setcpu "65816"
.segment "CODE"
.org $C6CA
map_control_0ec6ca:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
