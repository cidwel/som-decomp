.setcpu "65816"
.segment "CODE"
.org $FC99
map_control_0dfc99:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
