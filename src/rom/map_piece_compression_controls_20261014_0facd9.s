.setcpu "65816"
.segment "CODE"
.org $ACD9
map_control_0facd9:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
