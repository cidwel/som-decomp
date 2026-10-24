.setcpu "65816"
.segment "CODE"
.org $BE35
map_control_0fbe35:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
