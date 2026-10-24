.setcpu "65816"
.segment "CODE"
.org $42FC
map_control_0e42fc:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
