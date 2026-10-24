.setcpu "65816"
.segment "CODE"
.org $5A00
map_control_0d5a00:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
