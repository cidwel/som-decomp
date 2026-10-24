.setcpu "65816"
.segment "CODE"
.org $6F06
map_control_0e6f06:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
