.setcpu "65816"
.segment "CODE"
.org $3AFC
map_control_0c3afc:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
