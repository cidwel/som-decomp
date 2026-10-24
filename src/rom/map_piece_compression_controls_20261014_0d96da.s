.setcpu "65816"
.segment "CODE"
.org $96DA
map_control_0d96da:
    .byte $C2 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
