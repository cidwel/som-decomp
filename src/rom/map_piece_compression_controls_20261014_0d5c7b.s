.setcpu "65816"
.segment "CODE"
.org $5C7B
map_control_0d5c7b:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
