.setcpu "65816"
.segment "CODE"
.org $DE5C
map_control_0ede5c:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
    .byte $D1 ; same-value copy count/distance
