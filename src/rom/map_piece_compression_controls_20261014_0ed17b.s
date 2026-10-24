.setcpu "65816"
.segment "CODE"
.org $D17B
map_control_0ed17b:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
