.setcpu "65816"
.segment "CODE"
.org $3AB1
map_control_0c3ab1:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
