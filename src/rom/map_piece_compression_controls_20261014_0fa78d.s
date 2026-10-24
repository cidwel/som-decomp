.setcpu "65816"
.segment "CODE"
.org $A78D
map_control_0fa78d:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $C2 ; same-value copy count/distance
