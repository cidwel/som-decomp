.setcpu "65816"
.segment "CODE"
.org $0D8B
map_control_0e0d8b:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
