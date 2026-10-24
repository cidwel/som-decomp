.setcpu "65816"
.segment "CODE"
.org $6902
map_control_0f6902:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
