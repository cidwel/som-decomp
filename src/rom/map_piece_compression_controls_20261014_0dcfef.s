.setcpu "65816"
.segment "CODE"
.org $CFEF
map_control_0dcfef:
    .byte $E0 ; previous-row copy escape
    .byte $36 ; row-distance/count
