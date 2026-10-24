.setcpu "65816"
.segment "CODE"
.org $4812
map_control_0f4812:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
