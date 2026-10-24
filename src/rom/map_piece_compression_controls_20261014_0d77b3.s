.setcpu "65816"
.segment "CODE"
.org $77B3
map_control_0d77b3:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
