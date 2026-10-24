.setcpu "65816"
.segment "CODE"
.org $FBA1
map_control_0dfba1:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
