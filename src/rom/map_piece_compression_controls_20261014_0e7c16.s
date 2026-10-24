.setcpu "65816"
.segment "CODE"
.org $7C16
map_control_0e7c16:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
