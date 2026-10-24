.setcpu "65816"
.segment "CODE"
.org $CD2E
map_control_0fcd2e:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
