.setcpu "65816"
.segment "CODE"
.org $6E13
map_control_0d6e13:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
