.setcpu "65816"
.segment "CODE"
.org $FCBD
map_control_0efcbd:
    .byte $E0 ; previous-row copy escape
    .byte $BE ; row-distance/count
