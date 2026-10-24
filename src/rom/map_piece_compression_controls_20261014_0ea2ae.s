.setcpu "65816"
.segment "CODE"
.org $A2AE
map_control_0ea2ae:
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $C6 ; same-value copy count/distance
