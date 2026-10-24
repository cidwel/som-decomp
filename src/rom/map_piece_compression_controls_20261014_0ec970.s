.setcpu "65816"
.segment "CODE"
.org $C970
map_control_0ec970:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
