.setcpu "65816"
.segment "CODE"
.org $FCEA
map_control_0efcea:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
