.setcpu "65816"
.segment "CODE"
.org $6D23
map_control_0e6d23:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
