.setcpu "65816"
.segment "CODE"
.org $4C63
map_control_0f4c63:
    .byte $E0 ; previous-row copy escape
    .byte $49 ; row-distance/count
