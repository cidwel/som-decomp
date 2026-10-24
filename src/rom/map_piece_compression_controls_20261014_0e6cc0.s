.setcpu "65816"
.segment "CODE"
.org $6CC0
map_control_0e6cc0:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
