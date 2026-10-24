.setcpu "65816"
.segment "CODE"
.org $EF2D
map_control_0def2d:
    .byte $D1 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
