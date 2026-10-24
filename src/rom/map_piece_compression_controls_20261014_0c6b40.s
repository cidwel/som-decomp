.setcpu "65816"
.segment "CODE"
.org $6B40
map_control_0c6b40:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
