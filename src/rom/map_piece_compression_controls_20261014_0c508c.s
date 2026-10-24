.setcpu "65816"
.segment "CODE"
.org $508C
map_control_0c508c:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
