.setcpu "65816"
.segment "CODE"
.org $830D
map_control_0f830d:
    .byte $EB ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
