.setcpu "65816"
.segment "CODE"
.org $EBE0
map_control_0eebe0:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
