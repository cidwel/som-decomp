.setcpu "65816"
.segment "CODE"
.org $0861
map_control_0d0861:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
