.setcpu "65816"
.segment "CODE"
.org $38BE
map_control_0f38be:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
