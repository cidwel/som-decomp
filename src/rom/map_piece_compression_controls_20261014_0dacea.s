.setcpu "65816"
.segment "CODE"
.org $ACEA
map_control_0dacea:
    .byte $E0 ; previous-row copy escape
    .byte $56 ; row-distance/count
