.setcpu "65816"
.segment "CODE"
.org $90AF
map_control_0c90af:
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
