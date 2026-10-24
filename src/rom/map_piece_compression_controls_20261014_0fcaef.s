.setcpu "65816"
.segment "CODE"
.org $CAEF
map_control_0fcaef:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
