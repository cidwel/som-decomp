.setcpu "65816"
.segment "CODE"
.org $BCE4
map_control_0dbce4:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
