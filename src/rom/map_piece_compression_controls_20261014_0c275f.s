.setcpu "65816"
.segment "CODE"
.org $275F
map_control_0c275f:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
