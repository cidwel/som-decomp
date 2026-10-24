.setcpu "65816"
.segment "CODE"
.org $459A
map_control_0e459a:
    .byte $E2 ; previous-row copy count
    .byte $D9 ; same-value copy count/distance
