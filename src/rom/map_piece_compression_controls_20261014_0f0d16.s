.setcpu "65816"
.segment "CODE"
.org $0D16
map_control_0f0d16:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
