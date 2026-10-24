.setcpu "65816"
.segment "CODE"
.org $BA6E
map_control_0fba6e:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
