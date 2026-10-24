.setcpu "65816"
.segment "CODE"
.org $5CB6
map_control_0c5cb6:
    .byte $C2 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
