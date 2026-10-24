.setcpu "65816"
.segment "CODE"
.org $0F42
map_control_0e0f42:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
