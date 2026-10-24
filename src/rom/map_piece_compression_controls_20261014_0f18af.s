.setcpu "65816"
.segment "CODE"
.org $18AF
map_control_0f18af:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
