.setcpu "65816"
.segment "CODE"
.org $E1FE
map_control_0de1fe:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
