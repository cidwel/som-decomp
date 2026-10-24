.setcpu "65816"
.segment "CODE"
.org $A231
map_control_0fa231:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
