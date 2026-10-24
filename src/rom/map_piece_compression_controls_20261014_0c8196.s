.setcpu "65816"
.segment "CODE"
.org $8196
map_control_0c8196:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
