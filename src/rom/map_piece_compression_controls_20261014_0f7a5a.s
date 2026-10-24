.setcpu "65816"
.segment "CODE"
.org $7A5A
map_control_0f7a5a:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
