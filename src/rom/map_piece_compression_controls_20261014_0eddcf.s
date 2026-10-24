.setcpu "65816"
.segment "CODE"
.org $DDCF
map_control_0eddcf:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
