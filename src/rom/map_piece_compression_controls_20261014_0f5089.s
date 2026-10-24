.setcpu "65816"
.segment "CODE"
.org $5089
map_control_0f5089:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
