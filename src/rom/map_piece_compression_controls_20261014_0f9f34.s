.setcpu "65816"
.segment "CODE"
.org $9F34
map_control_0f9f34:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
