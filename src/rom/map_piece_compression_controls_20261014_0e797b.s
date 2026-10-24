.setcpu "65816"
.segment "CODE"
.org $797B
map_control_0e797b:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
