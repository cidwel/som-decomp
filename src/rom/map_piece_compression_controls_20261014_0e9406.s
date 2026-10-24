.setcpu "65816"
.segment "CODE"
.org $9406
map_control_0e9406:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
