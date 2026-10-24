.setcpu "65816"
.segment "CODE"
.org $6B4A
map_control_0e6b4a:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
