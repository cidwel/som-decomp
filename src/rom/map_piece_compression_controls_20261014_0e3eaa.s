.setcpu "65816"
.segment "CODE"
.org $3EAA
map_control_0e3eaa:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
