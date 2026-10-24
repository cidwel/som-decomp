.setcpu "65816"
.segment "CODE"
.org $327A
map_control_0d327a:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
