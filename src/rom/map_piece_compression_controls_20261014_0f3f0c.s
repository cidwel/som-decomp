.setcpu "65816"
.segment "CODE"
.org $3F0C
map_control_0f3f0c:
    .byte $E0 ; previous-row copy escape
    .byte $A1 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
