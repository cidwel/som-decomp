.setcpu "65816"
.segment "CODE"
.org $6889
map_control_0f6889:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
