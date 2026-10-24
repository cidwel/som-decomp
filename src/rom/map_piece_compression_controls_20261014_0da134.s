.setcpu "65816"
.segment "CODE"
.org $A134
map_control_0da134:
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
