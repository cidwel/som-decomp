.setcpu "65816"
.segment "CODE"
.org $1AFC
map_control_0c1afc:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
