.setcpu "65816"
.segment "CODE"
.org $FD5A
map_control_0dfd5a:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $E2 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
