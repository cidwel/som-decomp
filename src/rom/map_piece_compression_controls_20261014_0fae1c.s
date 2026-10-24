.setcpu "65816"
.segment "CODE"
.org $AE1C
map_control_0fae1c:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
