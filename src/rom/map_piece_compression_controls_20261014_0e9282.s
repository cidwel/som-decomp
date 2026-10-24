.setcpu "65816"
.segment "CODE"
.org $9282
map_control_0e9282:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
