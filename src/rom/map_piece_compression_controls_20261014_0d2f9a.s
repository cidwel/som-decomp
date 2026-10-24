.setcpu "65816"
.segment "CODE"
.org $2F9A
map_control_0d2f9a:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
