.setcpu "65816"
.segment "CODE"
.org $FCEF
map_control_0efcef:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
