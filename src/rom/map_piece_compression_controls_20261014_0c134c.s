.setcpu "65816"
.segment "CODE"
.org $134C
map_control_0c134c:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
