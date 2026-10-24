.setcpu "65816"
.segment "CODE"
.org $AAEF
map_control_0faaef:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
