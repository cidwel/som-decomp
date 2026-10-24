.setcpu "65816"
.segment "CODE"
.org $2D21
map_control_0d2d21:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
