.setcpu "65816"
.segment "CODE"
.org $C330
map_control_0dc330:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
