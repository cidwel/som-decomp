.setcpu "65816"
.segment "CODE"
.org $88ED
map_control_0f88ed:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
