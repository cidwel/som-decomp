.setcpu "65816"
.segment "CODE"
.org $AE11
map_control_0fae11:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
