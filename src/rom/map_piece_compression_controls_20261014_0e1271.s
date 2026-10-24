.setcpu "65816"
.segment "CODE"
.org $1271
map_control_0e1271:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $3D ; row-distance/count
