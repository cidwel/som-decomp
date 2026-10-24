.setcpu "65816"
.segment "CODE"
.org $E53C
map_control_0fe53c:
    .byte $E0 ; previous-row copy escape
    .byte $AD ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $54 ; row-distance/count
