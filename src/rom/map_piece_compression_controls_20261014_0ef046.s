.setcpu "65816"
.segment "CODE"
.org $F046
map_control_0ef046:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
