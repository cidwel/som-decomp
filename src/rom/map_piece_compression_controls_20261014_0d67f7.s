.setcpu "65816"
.segment "CODE"
.org $67F7
map_control_0d67f7:
    .byte $D3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
