.setcpu "65816"
.segment "CODE"
.org $E3D2
map_control_0de3d2:
    .byte $C4 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
