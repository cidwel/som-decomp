.setcpu "65816"
.segment "CODE"
.org $E4F1
map_control_0fe4f1:
    .byte $D7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
