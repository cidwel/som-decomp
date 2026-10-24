.setcpu "65816"
.segment "CODE"
.org $CD6A
map_control_0fcd6a:
    .byte $E3 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
