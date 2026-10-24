.setcpu "65816"
.segment "CODE"
.org $2A3D
map_control_0e2a3d:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
    .byte $C4 ; same-value copy count/distance
