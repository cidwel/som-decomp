.setcpu "65816"
.segment "CODE"
.org $43D4
map_control_0f43d4:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
