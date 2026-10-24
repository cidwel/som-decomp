.setcpu "65816"
.segment "CODE"
.org $2194
map_control_0d2194:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
