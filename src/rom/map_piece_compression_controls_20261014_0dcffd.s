.setcpu "65816"
.segment "CODE"
.org $CFFD
map_control_0dcffd:
    .byte $E0 ; previous-row copy escape
    .byte $3B ; row-distance/count
