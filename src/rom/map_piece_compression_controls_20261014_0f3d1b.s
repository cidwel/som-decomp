.setcpu "65816"
.segment "CODE"
.org $3D1B
map_control_0f3d1b:
    .byte $C3 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
