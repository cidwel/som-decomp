.setcpu "65816"
.segment "CODE"
.org $13F5
map_control_0e13f5:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
