.setcpu "65816"
.segment "CODE"
.org $198B
map_control_0f198b:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
