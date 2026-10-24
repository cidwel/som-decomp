.setcpu "65816"
.segment "CODE"
.org $3080
map_control_0c3080:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
