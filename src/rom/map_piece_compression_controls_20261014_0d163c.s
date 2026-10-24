.setcpu "65816"
.segment "CODE"
.org $163C
map_control_0d163c:
    .byte $E0 ; previous-row copy escape
    .byte $30 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
