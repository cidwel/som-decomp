.setcpu "65816"
.segment "CODE"
.org $AFDA
map_control_0fafda:
    .byte $E0 ; previous-row copy escape
    .byte $45 ; row-distance/count
