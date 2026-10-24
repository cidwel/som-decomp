.setcpu "65816"
.segment "CODE"
.org $0214
map_control_0f0214:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
