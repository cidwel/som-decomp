.setcpu "65816"
.segment "CODE"
.org $7F7E
map_control_0f7f7e:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
