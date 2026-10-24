.setcpu "65816"
.segment "CODE"
.org $F201
map_control_0df201:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
