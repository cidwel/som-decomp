.setcpu "65816"
.segment "CODE"
.org $7A94
map_control_0d7a94:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
