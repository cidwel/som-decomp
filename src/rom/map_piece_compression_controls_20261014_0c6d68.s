.setcpu "65816"
.segment "CODE"
.org $6D68
map_control_0c6d68:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
