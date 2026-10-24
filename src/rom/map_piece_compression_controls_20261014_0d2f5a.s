.setcpu "65816"
.segment "CODE"
.org $2F5A
map_control_0d2f5a:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
