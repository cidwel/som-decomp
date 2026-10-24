.setcpu "65816"
.segment "CODE"
.org $4C48
map_control_0f4c48:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C1 ; same-value copy count/distance
