.setcpu "65816"
.segment "CODE"
.org $3A2E
map_control_0c3a2e:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
