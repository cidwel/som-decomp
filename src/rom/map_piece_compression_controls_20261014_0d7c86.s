.setcpu "65816"
.segment "CODE"
.org $7C86
map_control_0d7c86:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $C1 ; same-value copy count/distance
