.setcpu "65816"
.segment "CODE"
.org $8107
map_control_0d8107:
    .byte $C1 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
