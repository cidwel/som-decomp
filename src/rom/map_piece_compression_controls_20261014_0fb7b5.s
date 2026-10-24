.setcpu "65816"
.segment "CODE"
.org $B7B5
map_control_0fb7b5:
    .byte $C1 ; same-value copy count/distance
    .byte $DF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $30 ; row-distance/count
