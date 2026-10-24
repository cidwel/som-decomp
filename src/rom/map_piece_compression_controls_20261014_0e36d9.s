.setcpu "65816"
.segment "CODE"
.org $36D9
map_control_0e36d9:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
