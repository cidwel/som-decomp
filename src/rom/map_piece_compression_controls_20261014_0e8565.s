.setcpu "65816"
.segment "CODE"
.org $8565
map_control_0e8565:
    .byte $E0 ; previous-row copy escape
    .byte $A3 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
