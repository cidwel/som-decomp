.setcpu "65816"
.segment "CODE"
.org $69CE
map_control_0f69ce:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
