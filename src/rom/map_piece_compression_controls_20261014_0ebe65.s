.setcpu "65816"
.segment "CODE"
.org $BE65
map_control_0ebe65:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
