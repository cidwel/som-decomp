.setcpu "65816"
.segment "CODE"
.org $BCED
map_control_0fbced:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
