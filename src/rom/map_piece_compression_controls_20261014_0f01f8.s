.setcpu "65816"
.segment "CODE"
.org $01F8
map_control_0f01f8:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
