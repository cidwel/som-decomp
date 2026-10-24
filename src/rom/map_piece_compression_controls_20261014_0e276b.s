.setcpu "65816"
.segment "CODE"
.org $276B
map_control_0e276b:
    .byte $C9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $39 ; row-distance/count
    .byte $D5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $39 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
