.setcpu "65816"
.segment "CODE"
.org $8E51
map_control_0e8e51:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
