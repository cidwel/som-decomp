.setcpu "65816"
.segment "CODE"
.org $9030
map_control_0f9030:
    .byte $C4 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
