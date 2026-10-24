.setcpu "65816"
.segment "CODE"
.org $BA68
map_control_0fba68:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
