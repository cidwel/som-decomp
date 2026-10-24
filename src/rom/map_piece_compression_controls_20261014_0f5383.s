.setcpu "65816"
.segment "CODE"
.org $5383
map_control_0f5383:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
