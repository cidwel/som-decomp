.setcpu "65816"
.segment "CODE"
.org $411D
map_control_0c411d:
    .byte $F1 ; progressive-copy count
    .byte $DF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
