.setcpu "65816"
.segment "CODE"
.org $9F37
map_control_0d9f37:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
