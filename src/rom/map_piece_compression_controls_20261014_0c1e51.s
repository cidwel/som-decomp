.setcpu "65816"
.segment "CODE"
.org $1E51
map_control_0c1e51:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
