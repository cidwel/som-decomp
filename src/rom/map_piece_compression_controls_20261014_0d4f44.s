.setcpu "65816"
.segment "CODE"
.org $4F44
map_control_0d4f44:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
