.setcpu "65816"
.segment "CODE"
.org $47E3
map_control_0c47e3:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
