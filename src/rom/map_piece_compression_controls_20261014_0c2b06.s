.setcpu "65816"
.segment "CODE"
.org $2B06
map_control_0c2b06:
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
