.setcpu "65816"
.segment "CODE"
.org $2D45
map_control_0d2d45:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
