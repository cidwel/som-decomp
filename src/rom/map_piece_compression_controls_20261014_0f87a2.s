.setcpu "65816"
.segment "CODE"
.org $87A2
map_control_0f87a2:
    .byte $E0 ; previous-row copy escape
    .byte $E5 ; row-distance/count
