.setcpu "65816"
.segment "CODE"
.org $7F5A
map_control_0f7f5a:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
