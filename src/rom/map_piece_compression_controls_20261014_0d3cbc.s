.setcpu "65816"
.segment "CODE"
.org $3CBC
map_control_0d3cbc:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $AD ; row-distance/count
    .byte $C1 ; same-value copy count/distance
