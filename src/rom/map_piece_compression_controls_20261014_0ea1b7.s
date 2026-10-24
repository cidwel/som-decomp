.setcpu "65816"
.segment "CODE"
.org $A1B7
map_control_0ea1b7:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
