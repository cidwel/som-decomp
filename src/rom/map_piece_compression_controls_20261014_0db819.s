.setcpu "65816"
.segment "CODE"
.org $B819
map_control_0db819:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
