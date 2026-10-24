.setcpu "65816"
.segment "CODE"
.org $9AFC
map_control_0f9afc:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
