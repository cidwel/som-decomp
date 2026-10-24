.setcpu "65816"
.segment "CODE"
.org $6958
map_control_0e6958:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
