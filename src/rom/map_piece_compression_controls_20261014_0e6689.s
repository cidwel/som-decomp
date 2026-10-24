.setcpu "65816"
.segment "CODE"
.org $6689
map_control_0e6689:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
