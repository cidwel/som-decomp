.setcpu "65816"
.segment "CODE"
.org $395B
map_control_0c395b:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
    .byte $C1 ; same-value copy count/distance
