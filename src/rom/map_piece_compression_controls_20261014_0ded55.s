.setcpu "65816"
.segment "CODE"
.org $ED55
map_control_0ded55:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
