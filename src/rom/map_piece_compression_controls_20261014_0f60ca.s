.setcpu "65816"
.segment "CODE"
.org $60CA
map_control_0f60ca:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
