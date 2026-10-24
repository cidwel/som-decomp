.setcpu "65816"
.segment "CODE"
.org $BABA
map_control_0ebaba:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
