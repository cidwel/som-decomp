.setcpu "65816"
.segment "CODE"
.org $ABD8
map_control_0fabd8:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
