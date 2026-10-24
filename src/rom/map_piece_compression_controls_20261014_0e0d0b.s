.setcpu "65816"
.segment "CODE"
.org $0D0B
map_control_0e0d0b:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
