.setcpu "65816"
.segment "CODE"
.org $7927
map_control_0c7927:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C1 ; same-value copy count/distance
