.setcpu "65816"
.segment "CODE"
.org $CFFA
map_control_0dcffa:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
