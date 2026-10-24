.setcpu "65816"
.segment "CODE"
.org $048F
map_control_0e048f:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
