.setcpu "65816"
.segment "CODE"
.org $00C1
map_control_0e00c1:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
