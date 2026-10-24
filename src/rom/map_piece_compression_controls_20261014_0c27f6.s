.setcpu "65816"
.segment "CODE"
.org $27F6
map_control_0c27f6:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
