.setcpu "65816"
.segment "CODE"
.org $7EC0
map_control_0d7ec0:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
