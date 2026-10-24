.setcpu "65816"
.segment "CODE"
.org $1C6C
map_control_0d1c6c:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
