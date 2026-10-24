.setcpu "65816"
.segment "CODE"
.org $6D86
map_control_0e6d86:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
