.setcpu "65816"
.segment "CODE"
.org $4372
map_control_0c4372:
    .byte $C7 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
