.setcpu "65816"
.segment "CODE"
.org $66EE
map_control_0d66ee:
    .byte $DF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
    .byte $E4 ; previous-row copy count
