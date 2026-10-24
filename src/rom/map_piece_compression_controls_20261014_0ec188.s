.setcpu "65816"
.segment "CODE"
.org $C188
map_control_0ec188:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $C6 ; same-value copy count/distance
