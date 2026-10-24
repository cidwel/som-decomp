.setcpu "65816"
.segment "CODE"
.org $57A9
map_control_0c57a9:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
