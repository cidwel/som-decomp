.setcpu "65816"
.segment "CODE"
.org $7A9A
map_control_0f7a9a:
    .byte $C1 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
