.setcpu "65816"
.segment "CODE"
.org $BDE8
map_control_0ebde8:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
