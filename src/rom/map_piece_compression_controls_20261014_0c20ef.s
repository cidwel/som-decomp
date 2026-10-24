.setcpu "65816"
.segment "CODE"
.org $20EF
map_control_0c20ef:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
