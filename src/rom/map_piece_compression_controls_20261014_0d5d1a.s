.setcpu "65816"
.segment "CODE"
.org $5D1A
map_control_0d5d1a:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
