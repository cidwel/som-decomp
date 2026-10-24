.setcpu "65816"
.segment "CODE"
.org $E716
map_control_0fe716:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
