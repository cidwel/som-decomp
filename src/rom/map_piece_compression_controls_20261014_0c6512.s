.setcpu "65816"
.segment "CODE"
.org $6512
map_control_0c6512:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
    .byte $C3 ; same-value copy count/distance
