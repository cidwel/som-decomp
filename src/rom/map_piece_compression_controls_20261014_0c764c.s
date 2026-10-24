.setcpu "65816"
.segment "CODE"
.org $764C
map_control_0c764c:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
