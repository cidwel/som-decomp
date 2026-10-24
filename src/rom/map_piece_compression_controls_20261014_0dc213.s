.setcpu "65816"
.segment "CODE"
.org $C213
map_control_0dc213:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
