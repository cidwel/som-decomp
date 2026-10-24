.setcpu "65816"
.segment "CODE"
.org $AD77
map_control_0fad77:
    .byte $D2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
