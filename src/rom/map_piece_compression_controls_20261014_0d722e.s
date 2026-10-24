.setcpu "65816"
.segment "CODE"
.org $722E
map_control_0d722e:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
