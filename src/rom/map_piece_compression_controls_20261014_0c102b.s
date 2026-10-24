.setcpu "65816"
.segment "CODE"
.org $102B
map_control_0c102b:
    .byte $D9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
