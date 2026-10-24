.setcpu "65816"
.segment "CODE"
.org $1565
map_control_0f1565:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
