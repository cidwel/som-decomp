.setcpu "65816"
.segment "CODE"
.org $22DF
map_control_0f22df:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
