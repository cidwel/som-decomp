.setcpu "65816"
.segment "CODE"
.org $7DE2
map_control_0f7de2:
    .byte $EB ; backreference distance high bits
    .byte $91 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
