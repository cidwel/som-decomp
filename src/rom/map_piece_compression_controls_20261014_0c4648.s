.setcpu "65816"
.segment "CODE"
.org $4648
map_control_0c4648:
    .byte $C4 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
