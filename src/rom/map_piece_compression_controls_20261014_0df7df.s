.setcpu "65816"
.segment "CODE"
.org $F7DF
map_control_0df7df:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
