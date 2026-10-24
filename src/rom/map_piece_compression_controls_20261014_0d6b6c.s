.setcpu "65816"
.segment "CODE"
.org $6B6C
map_control_0d6b6c:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
