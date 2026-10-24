.setcpu "65816"
.segment "CODE"
.org $7E5D
map_control_0d7e5d:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $D1 ; same-value copy count/distance
