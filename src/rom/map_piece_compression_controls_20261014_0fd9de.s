.setcpu "65816"
.segment "CODE"
.org $D9DE
map_control_0fd9de:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
