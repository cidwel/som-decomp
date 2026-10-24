.setcpu "65816"
.segment "CODE"
.org $DC96
map_control_0fdc96:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $A0 ; row-distance/count
    .byte $E1 ; previous-row copy count
