.setcpu "65816"
.segment "CODE"
.org $E6D9
map_control_0de6d9:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
