.setcpu "65816"
.segment "CODE"
.org $9403
map_control_0e9403:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
