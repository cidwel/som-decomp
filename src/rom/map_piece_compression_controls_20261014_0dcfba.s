.setcpu "65816"
.segment "CODE"
.org $CFBA
map_control_0dcfba:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
