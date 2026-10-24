.setcpu "65816"
.segment "CODE"
.org $09E8
map_control_0d09e8:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
