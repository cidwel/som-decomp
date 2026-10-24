.setcpu "65816"
.segment "CODE"
.org $AB09
map_control_0eab09:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
