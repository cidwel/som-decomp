.setcpu "65816"
.segment "CODE"
.org $5B76
map_control_0e5b76:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
