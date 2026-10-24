.setcpu "65816"
.segment "CODE"
.org $D9D7
map_control_0ed9d7:
    .byte $DF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
