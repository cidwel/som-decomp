.setcpu "65816"
.segment "CODE"
.org $5CDD
map_control_0c5cdd:
    .byte $C2 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
