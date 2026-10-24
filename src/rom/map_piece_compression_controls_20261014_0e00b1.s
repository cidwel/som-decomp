.setcpu "65816"
.segment "CODE"
.org $00B1
map_control_0e00b1:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
