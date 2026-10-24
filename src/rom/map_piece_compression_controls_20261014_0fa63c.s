.setcpu "65816"
.segment "CODE"
.org $A63C
map_control_0fa63c:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
