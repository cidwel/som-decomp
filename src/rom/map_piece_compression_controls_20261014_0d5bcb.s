.setcpu "65816"
.segment "CODE"
.org $5BCB
map_control_0d5bcb:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
