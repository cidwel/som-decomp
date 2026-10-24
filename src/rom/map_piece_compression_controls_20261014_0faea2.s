.setcpu "65816"
.segment "CODE"
.org $AEA2
map_control_0faea2:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
