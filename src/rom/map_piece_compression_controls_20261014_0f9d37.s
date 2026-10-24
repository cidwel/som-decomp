.setcpu "65816"
.segment "CODE"
.org $9D37
map_control_0f9d37:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
