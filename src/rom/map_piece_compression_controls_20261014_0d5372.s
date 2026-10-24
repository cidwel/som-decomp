.setcpu "65816"
.segment "CODE"
.org $5372
map_control_0d5372:
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
