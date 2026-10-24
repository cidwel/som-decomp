.setcpu "65816"
.segment "CODE"
.org $9A01
map_control_0e9a01:
    .byte $E0 ; previous-row copy escape
    .byte $B5 ; row-distance/count
