.setcpu "65816"
.segment "CODE"
.org $4EC8
map_control_0f4ec8:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
