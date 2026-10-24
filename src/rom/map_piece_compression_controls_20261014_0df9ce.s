.setcpu "65816"
.segment "CODE"
.org $F9CE
map_control_0df9ce:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
