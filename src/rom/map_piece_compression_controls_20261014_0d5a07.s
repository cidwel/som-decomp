.setcpu "65816"
.segment "CODE"
.org $5A07
map_control_0d5a07:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
