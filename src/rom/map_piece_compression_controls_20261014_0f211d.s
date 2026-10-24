.setcpu "65816"
.segment "CODE"
.org $211D
map_control_0f211d:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
