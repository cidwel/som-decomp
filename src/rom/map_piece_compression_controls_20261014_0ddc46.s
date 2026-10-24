.setcpu "65816"
.segment "CODE"
.org $DC46
map_control_0ddc46:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
