.setcpu "65816"
.segment "CODE"
.org $AF36
map_control_0faf36:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
