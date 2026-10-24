.setcpu "65816"
.segment "CODE"
.org $694A
map_control_0f694a:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
