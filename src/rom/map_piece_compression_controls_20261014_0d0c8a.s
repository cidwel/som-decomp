.setcpu "65816"
.segment "CODE"
.org $0C8A
map_control_0d0c8a:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
