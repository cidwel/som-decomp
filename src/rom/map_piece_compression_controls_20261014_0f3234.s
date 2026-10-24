.setcpu "65816"
.segment "CODE"
.org $3234
map_control_0f3234:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
