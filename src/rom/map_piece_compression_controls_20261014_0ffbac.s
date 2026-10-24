.setcpu "65816"
.segment "CODE"
.org $FBAC
map_control_0ffbac:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
