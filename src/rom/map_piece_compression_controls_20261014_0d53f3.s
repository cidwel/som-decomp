.setcpu "65816"
.segment "CODE"
.org $53F3
map_control_0d53f3:
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
