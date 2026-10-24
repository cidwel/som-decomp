.setcpu "65816"
.segment "CODE"
.org $3741
map_control_0c3741:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
