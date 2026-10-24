.setcpu "65816"
.segment "CODE"
.org $68E1
map_control_0c68e1:
    .byte $C9 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
