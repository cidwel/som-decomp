.setcpu "65816"
.segment "CODE"
.org $CFCA
map_control_0dcfca:
    .byte $E0 ; previous-row copy escape
    .byte $3B ; row-distance/count
