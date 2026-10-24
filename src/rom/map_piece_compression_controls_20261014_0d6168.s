.setcpu "65816"
.segment "CODE"
.org $6168
map_control_0d6168:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
