.setcpu "65816"
.segment "CODE"
.org $E77E
map_control_0de77e:
    .byte $E1 ; previous-row copy count
    .byte $D4 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
