.setcpu "65816"
.segment "CODE"
.org $0800
map_control_0f0800:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
