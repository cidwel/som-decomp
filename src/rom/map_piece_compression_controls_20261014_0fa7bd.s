.setcpu "65816"
.segment "CODE"
.org $A7BD
map_control_0fa7bd:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
    .byte $C2 ; same-value copy count/distance
