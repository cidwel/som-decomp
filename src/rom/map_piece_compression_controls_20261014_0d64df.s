.setcpu "65816"
.segment "CODE"
.org $64DF
map_control_0d64df:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
