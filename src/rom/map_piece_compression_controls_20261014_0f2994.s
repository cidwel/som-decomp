.setcpu "65816"
.segment "CODE"
.org $2994
map_control_0f2994:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
