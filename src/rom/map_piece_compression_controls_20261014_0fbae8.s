.setcpu "65816"
.segment "CODE"
.org $BAE8
map_control_0fbae8:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
