.setcpu "65816"
.segment "CODE"
.org $656E
map_control_0e656e:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C4 ; same-value copy count/distance
