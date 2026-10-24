.setcpu "65816"
.segment "CODE"
.org $9F59
map_control_0f9f59:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
