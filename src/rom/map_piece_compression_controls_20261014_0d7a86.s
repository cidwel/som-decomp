.setcpu "65816"
.segment "CODE"
.org $7A86
map_control_0d7a86:
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
