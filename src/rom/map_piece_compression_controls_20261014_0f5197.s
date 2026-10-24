.setcpu "65816"
.segment "CODE"
.org $5197
map_control_0f5197:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
