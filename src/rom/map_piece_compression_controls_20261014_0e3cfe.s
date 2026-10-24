.setcpu "65816"
.segment "CODE"
.org $3CFE
map_control_0e3cfe:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
