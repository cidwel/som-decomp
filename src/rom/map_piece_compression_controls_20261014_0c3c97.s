.setcpu "65816"
.segment "CODE"
.org $3C97
map_control_0c3c97:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
