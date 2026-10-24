.setcpu "65816"
.segment "CODE"
.org $128E
map_control_0f128e:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
