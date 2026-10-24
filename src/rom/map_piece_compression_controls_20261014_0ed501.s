.setcpu "65816"
.segment "CODE"
.org $D501
map_control_0ed501:
    .byte $DF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
