.setcpu "65816"
.segment "CODE"
.org $0F28
map_control_0f0f28:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
