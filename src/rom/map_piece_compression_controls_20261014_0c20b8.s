.setcpu "65816"
.segment "CODE"
.org $20B8
map_control_0c20b8:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
