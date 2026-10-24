.setcpu "65816"
.segment "CODE"
.org $EABA
map_control_0deaba:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
