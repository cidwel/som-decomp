.setcpu "65816"
.segment "CODE"
.org $11D5
map_control_0c11d5:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
