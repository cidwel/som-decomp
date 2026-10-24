.setcpu "65816"
.segment "CODE"
.org $3FFF
map_control_0c3fff:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
