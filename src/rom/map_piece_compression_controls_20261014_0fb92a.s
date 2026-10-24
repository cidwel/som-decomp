.setcpu "65816"
.segment "CODE"
.org $B92A
map_control_0fb92a:
    .byte $E0 ; previous-row copy escape
    .byte $30 ; row-distance/count
