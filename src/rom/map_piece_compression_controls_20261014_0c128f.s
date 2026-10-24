.setcpu "65816"
.segment "CODE"
.org $128F
map_control_0c128f:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
