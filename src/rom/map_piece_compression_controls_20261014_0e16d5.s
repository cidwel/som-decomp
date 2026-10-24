.setcpu "65816"
.segment "CODE"
.org $16D5
map_control_0e16d5:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
