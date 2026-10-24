.setcpu "65816"
.segment "CODE"
.org $A413
map_control_0ea413:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $D7 ; same-value copy count/distance
