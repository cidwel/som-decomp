.setcpu "65816"
.segment "CODE"
.org $3D83
map_control_0c3d83:
    .byte $E6 ; previous-row copy count
    .byte $F1 ; progressive-copy count
    .byte $D1 ; same-value copy count/distance
