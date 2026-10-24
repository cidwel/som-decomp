.setcpu "65816"
.segment "CODE"
.org $FEEB
map_control_0efeeb:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
