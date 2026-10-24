.setcpu "65816"
.segment "CODE"
.org $9810
map_control_0f9810:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
