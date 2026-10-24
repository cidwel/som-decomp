.setcpu "65816"
.segment "CODE"
.org $BEBE
map_control_0fbebe:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
