.setcpu "65816"
.segment "CODE"
.org $A176
map_control_0da176:
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
