.setcpu "65816"
.segment "CODE"
.org $FC40
map_control_0dfc40:
    .byte $C9 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
