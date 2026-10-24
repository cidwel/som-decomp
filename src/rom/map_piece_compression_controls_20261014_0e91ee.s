.setcpu "65816"
.segment "CODE"
.org $91EE
map_control_0e91ee:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
