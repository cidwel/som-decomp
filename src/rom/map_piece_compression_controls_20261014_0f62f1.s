.setcpu "65816"
.segment "CODE"
.org $62F1
map_control_0f62f1:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
