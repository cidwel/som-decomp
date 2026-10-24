.setcpu "65816"
.segment "CODE"
.org $3D68
map_control_0e3d68:
    .byte $C6 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
