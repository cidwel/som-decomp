.setcpu "65816"
.segment "CODE"
.org $6117
map_control_0f6117:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
