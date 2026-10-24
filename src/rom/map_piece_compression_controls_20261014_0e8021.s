.setcpu "65816"
.segment "CODE"
.org $8021
map_control_0e8021:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
