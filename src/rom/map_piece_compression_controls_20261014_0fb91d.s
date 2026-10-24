.setcpu "65816"
.segment "CODE"
.org $B91D
map_control_0fb91d:
    .byte $E0 ; previous-row copy escape
    .byte $30 ; row-distance/count
