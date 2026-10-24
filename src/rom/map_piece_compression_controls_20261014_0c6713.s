.setcpu "65816"
.segment "CODE"
.org $6713
map_control_0c6713:
    .byte $C4 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
