.setcpu "65816"
.segment "CODE"
.org $4A5C
map_control_0d4a5c:
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
