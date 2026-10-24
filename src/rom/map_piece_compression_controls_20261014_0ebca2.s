.setcpu "65816"
.segment "CODE"
.org $BCA2
map_control_0ebca2:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
