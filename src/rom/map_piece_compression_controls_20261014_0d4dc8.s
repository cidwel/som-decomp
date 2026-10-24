.setcpu "65816"
.segment "CODE"
.org $4DC8
map_control_0d4dc8:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
