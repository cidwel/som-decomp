.setcpu "65816"
.segment "CODE"
.org $9F4C
map_control_0d9f4c:
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
