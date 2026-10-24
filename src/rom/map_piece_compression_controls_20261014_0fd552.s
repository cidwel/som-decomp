.setcpu "65816"
.segment "CODE"
.org $D552
map_control_0fd552:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
