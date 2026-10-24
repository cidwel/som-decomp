.setcpu "65816"
.segment "CODE"
.org $ABB2
map_control_0fabb2:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
