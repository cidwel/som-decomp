.setcpu "65816"
.segment "CODE"
.org $EE35
map_control_0eee35:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
