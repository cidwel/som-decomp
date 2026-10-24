.setcpu "65816"
.segment "CODE"
.org $307A
map_control_0d307a:
    .byte $E2 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
