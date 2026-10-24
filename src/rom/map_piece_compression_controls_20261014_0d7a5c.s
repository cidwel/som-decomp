.setcpu "65816"
.segment "CODE"
.org $7A5C
map_control_0d7a5c:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
