.setcpu "65816"
.segment "CODE"
.org $6C72
map_control_0d6c72:
    .byte $E0 ; previous-row copy escape
    .byte $BC ; row-distance/count
