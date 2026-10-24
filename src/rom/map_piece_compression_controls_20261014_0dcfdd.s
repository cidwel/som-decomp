.setcpu "65816"
.segment "CODE"
.org $CFDD
map_control_0dcfdd:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
