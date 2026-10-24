.setcpu "65816"
.segment "CODE"
.org $211D
map_control_0e211d:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
