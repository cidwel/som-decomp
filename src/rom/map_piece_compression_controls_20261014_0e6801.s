.setcpu "65816"
.segment "CODE"
.org $6801
map_control_0e6801:
    .byte $E3 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
