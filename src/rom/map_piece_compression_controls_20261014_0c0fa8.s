.setcpu "65816"
.segment "CODE"
.org $0FA8
map_control_0c0fa8:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
