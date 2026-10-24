.setcpu "65816"
.segment "CODE"
.org $7C26
map_control_0c7c26:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
