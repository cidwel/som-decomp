.setcpu "65816"
.segment "CODE"
.org $63FF
map_control_0d63ff:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
