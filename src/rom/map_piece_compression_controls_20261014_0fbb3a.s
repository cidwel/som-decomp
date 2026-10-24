.setcpu "65816"
.segment "CODE"
.org $BB3A
map_control_0fbb3a:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
