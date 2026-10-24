.setcpu "65816"
.segment "CODE"
.org $3F6F
map_control_0e3f6f:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
