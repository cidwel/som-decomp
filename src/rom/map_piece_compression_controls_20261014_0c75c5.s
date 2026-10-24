.setcpu "65816"
.segment "CODE"
.org $75C5
map_control_0c75c5:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
