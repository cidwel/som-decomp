.setcpu "65816"
.segment "CODE"
.org $2B96
map_control_0f2b96:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
