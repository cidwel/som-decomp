.setcpu "65816"
.segment "CODE"
.org $F030
map_control_0ff030:
    .byte $C2 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
