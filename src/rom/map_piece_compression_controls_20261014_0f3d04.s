.setcpu "65816"
.segment "CODE"
.org $3D04
map_control_0f3d04:
    .byte $C1 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
