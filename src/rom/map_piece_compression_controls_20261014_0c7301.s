.setcpu "65816"
.segment "CODE"
.org $7301
map_control_0c7301:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
