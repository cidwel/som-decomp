.setcpu "65816"
.segment "CODE"
.org $7C40
map_control_0c7c40:
    .byte $E0 ; previous-row copy escape
    .byte $3D ; row-distance/count
    .byte $C6 ; same-value copy count/distance
