.setcpu "65816"
.segment "CODE"
.org $BD1F
map_control_0dbd1f:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
