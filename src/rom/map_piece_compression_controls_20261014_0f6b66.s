.setcpu "65816"
.segment "CODE"
.org $6B66
map_control_0f6b66:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
