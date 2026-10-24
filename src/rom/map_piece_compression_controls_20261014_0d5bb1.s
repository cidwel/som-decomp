.setcpu "65816"
.segment "CODE"
.org $5BB1
map_control_0d5bb1:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
