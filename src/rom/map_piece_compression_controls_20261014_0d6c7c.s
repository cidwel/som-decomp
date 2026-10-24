.setcpu "65816"
.segment "CODE"
.org $6C7C
map_control_0d6c7c:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
