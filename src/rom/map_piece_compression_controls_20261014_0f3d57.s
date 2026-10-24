.setcpu "65816"
.segment "CODE"
.org $3D57
map_control_0f3d57:
    .byte $C4 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
