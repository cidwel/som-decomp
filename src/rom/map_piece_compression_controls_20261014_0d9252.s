.setcpu "65816"
.segment "CODE"
.org $9252
map_control_0d9252:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
