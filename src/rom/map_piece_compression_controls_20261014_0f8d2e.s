.setcpu "65816"
.segment "CODE"
.org $8D2E
map_control_0f8d2e:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
