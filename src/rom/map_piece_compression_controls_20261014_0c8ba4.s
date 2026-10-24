.setcpu "65816"
.segment "CODE"
.org $8BA4
map_control_0c8ba4:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
