.setcpu "65816"
.segment "CODE"
.org $DF57
map_control_0edf57:
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
