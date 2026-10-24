.setcpu "65816"
.segment "CODE"
.org $140F
map_control_0f140f:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
