.setcpu "65816"
.segment "CODE"
.org $7AC9
map_control_0f7ac9:
    .byte $C6 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
