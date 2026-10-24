.setcpu "65816"
.segment "CODE"
.org $CFF5
map_control_0dcff5:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
