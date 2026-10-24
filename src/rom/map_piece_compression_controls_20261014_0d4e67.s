.setcpu "65816"
.segment "CODE"
.org $4E67
map_control_0d4e67:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
