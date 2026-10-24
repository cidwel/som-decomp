.setcpu "65816"
.segment "CODE"
.org $2428
map_control_0d2428:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
