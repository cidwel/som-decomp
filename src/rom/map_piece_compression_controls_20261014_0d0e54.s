.setcpu "65816"
.segment "CODE"
.org $0E54
map_control_0d0e54:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
