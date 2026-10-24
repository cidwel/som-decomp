.setcpu "65816"
.segment "CODE"
.org $560E
map_control_0c560e:
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
