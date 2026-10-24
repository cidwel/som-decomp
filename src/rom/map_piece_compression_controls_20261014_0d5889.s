.setcpu "65816"
.segment "CODE"
.org $5889
map_control_0d5889:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
    .byte $E5 ; previous-row copy count
