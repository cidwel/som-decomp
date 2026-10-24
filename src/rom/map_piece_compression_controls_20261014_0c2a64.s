.setcpu "65816"
.segment "CODE"
.org $2A64
map_control_0c2a64:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
