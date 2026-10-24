.setcpu "65816"
.segment "CODE"
.org $8A06
map_control_0f8a06:
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
