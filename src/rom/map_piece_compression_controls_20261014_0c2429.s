.setcpu "65816"
.segment "CODE"
.org $2429
map_control_0c2429:
    .byte $E5 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
