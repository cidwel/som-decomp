.setcpu "65816"
.segment "CODE"
.org $FC1A
map_control_0dfc1a:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
