.setcpu "65816"
.segment "CODE"
.org $6BAD
map_control_0f6bad:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
