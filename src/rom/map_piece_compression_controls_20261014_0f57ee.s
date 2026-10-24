.setcpu "65816"
.segment "CODE"
.org $57EE
map_control_0f57ee:
    .byte $C1 ; same-value copy count/distance
    .byte $DF ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $D4 ; same-value copy count/distance
