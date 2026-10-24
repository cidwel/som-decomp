.setcpu "65816"
.segment "CODE"
.org $89CE
map_control_0d89ce:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
