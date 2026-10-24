.setcpu "65816"
.segment "CODE"
.org $6FF6
map_control_0e6ff6:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
