.setcpu "65816"
.segment "CODE"
.org $2B2E
map_control_0f2b2e:
    .byte $C2 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
