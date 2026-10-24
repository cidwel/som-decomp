.setcpu "65816"
.segment "CODE"
.org $FC31
map_control_0efc31:
    .byte $E0 ; previous-row copy escape
    .byte $B0 ; row-distance/count
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
