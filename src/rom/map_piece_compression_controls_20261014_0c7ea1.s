.setcpu "65816"
.segment "CODE"
.org $7EA1
map_control_0c7ea1:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
