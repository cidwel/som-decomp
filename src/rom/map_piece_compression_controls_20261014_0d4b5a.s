.setcpu "65816"
.segment "CODE"
.org $4B5A
map_control_0d4b5a:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
