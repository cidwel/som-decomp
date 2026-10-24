.setcpu "65816"
.segment "CODE"
.org $3D6E
map_control_0e3d6e:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
