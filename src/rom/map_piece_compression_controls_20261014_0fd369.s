.setcpu "65816"
.segment "CODE"
.org $D369
map_control_0fd369:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
