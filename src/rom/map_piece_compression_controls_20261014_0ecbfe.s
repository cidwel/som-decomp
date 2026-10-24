.setcpu "65816"
.segment "CODE"
.org $CBFE
map_control_0ecbfe:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
