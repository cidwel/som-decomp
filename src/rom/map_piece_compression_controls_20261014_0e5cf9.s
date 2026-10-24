.setcpu "65816"
.segment "CODE"
.org $5CF9
map_control_0e5cf9:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
