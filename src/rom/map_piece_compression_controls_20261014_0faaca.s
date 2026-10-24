.setcpu "65816"
.segment "CODE"
.org $AACA
map_control_0faaca:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
