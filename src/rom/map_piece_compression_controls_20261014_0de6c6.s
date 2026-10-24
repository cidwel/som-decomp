.setcpu "65816"
.segment "CODE"
.org $E6C6
map_control_0de6c6:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
