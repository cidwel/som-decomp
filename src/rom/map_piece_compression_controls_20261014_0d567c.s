.setcpu "65816"
.segment "CODE"
.org $567C
map_control_0d567c:
    .byte $C6 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
