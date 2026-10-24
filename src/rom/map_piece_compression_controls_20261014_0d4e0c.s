.setcpu "65816"
.segment "CODE"
.org $4E0C
map_control_0d4e0c:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
