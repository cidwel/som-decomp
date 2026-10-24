.setcpu "65816"
.segment "CODE"
.org $56FE
map_control_0f56fe:
    .byte $C2 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
