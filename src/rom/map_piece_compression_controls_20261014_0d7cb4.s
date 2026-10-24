.setcpu "65816"
.segment "CODE"
.org $7CB4
map_control_0d7cb4:
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
