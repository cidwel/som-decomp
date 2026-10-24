.setcpu "65816"
.segment "CODE"
.org $141D
map_control_0e141d:
    .byte $C1 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
