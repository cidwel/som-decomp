.setcpu "65816"
.segment "CODE"
.org $BDDA
map_control_0fbdda:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
