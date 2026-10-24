.setcpu "65816"
.segment "CODE"
.org $CB6A
map_control_0dcb6a:
    .byte $E8 ; backreference distance high bits
    .byte $24 ; distance low bit/count
