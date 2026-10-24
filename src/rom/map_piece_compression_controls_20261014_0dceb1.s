.setcpu "65816"
.segment "CODE"
.org $CEB1
map_control_0dceb1:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
