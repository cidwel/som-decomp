.setcpu "65816"
.segment "CODE"
.org $F9F6
map_control_0df9f6:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
