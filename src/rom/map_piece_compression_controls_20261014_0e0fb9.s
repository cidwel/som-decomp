.setcpu "65816"
.segment "CODE"
.org $0FB9
map_control_0e0fb9:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
