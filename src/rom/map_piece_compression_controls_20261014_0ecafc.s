.setcpu "65816"
.segment "CODE"
.org $CAFC
map_control_0ecafc:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
