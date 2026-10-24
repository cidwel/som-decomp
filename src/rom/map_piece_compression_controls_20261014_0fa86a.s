.setcpu "65816"
.segment "CODE"
.org $A86A
map_control_0fa86a:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
