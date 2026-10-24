.setcpu "65816"
.segment "CODE"
.org $BDFE
map_control_0dbdfe:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
