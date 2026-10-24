.setcpu "65816"
.segment "CODE"
.org $E92A
map_control_0de92a:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
