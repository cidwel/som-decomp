.setcpu "65816"
.segment "CODE"
.org $FED8
map_control_0efed8:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
