.setcpu "65816"
.segment "CODE"
.org $5C9A
map_control_0d5c9a:
    .byte $C1 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
