.setcpu "65816"
.segment "CODE"
.org $4AFF
map_control_0c4aff:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
