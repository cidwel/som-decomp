.setcpu "65816"
.segment "CODE"
.org $F0EB
map_control_0ef0eb:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
