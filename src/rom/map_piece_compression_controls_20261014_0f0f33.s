.setcpu "65816"
.segment "CODE"
.org $0F33
map_control_0f0f33:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
