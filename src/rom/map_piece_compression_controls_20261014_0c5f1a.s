.setcpu "65816"
.segment "CODE"
.org $5F1A
map_control_0c5f1a:
    .byte $E0 ; previous-row copy escape
    .byte $B6 ; row-distance/count
