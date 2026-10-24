.setcpu "65816"
.segment "CODE"
.org $556A
map_control_0d556a:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
