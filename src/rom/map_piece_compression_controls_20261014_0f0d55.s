.setcpu "65816"
.segment "CODE"
.org $0D55
map_control_0f0d55:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
