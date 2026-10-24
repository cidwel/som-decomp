.setcpu "65816"
.segment "CODE"
.org $2A21
map_control_0d2a21:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
