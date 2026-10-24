.setcpu "65816"
.segment "CODE"
.org $BDDF
map_control_0dbddf:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
