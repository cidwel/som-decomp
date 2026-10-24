.setcpu "65816"
.segment "CODE"
.org $6A3A
map_control_0d6a3a:
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
