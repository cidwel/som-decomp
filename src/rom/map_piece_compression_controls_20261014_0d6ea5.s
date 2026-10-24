.setcpu "65816"
.segment "CODE"
.org $6EA5
map_control_0d6ea5:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
