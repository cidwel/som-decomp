.setcpu "65816"
.segment "CODE"
.org $E783
map_control_0de783:
    .byte $E1 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
