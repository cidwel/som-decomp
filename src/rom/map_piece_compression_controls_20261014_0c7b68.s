.setcpu "65816"
.segment "CODE"
.org $7B68
map_control_0c7b68:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
