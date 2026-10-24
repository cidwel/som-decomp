.setcpu "65816"
.segment "CODE"
.org $1C8A
map_control_0d1c8a:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
