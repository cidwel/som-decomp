.setcpu "65816"
.segment "CODE"
.org $51DF
map_control_0f51df:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
