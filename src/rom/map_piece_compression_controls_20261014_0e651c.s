.setcpu "65816"
.segment "CODE"
.org $651C
map_control_0e651c:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
