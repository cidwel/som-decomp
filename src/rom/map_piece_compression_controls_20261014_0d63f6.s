.setcpu "65816"
.segment "CODE"
.org $63F6
map_control_0d63f6:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
